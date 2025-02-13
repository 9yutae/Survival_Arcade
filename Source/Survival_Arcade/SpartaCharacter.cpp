#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"
#include "SpartaGameState.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/ProgressBar.h"

ASpartaCharacter::ASpartaCharacter()
{
	// Tick 함수 비활성화
	PrimaryActorTick.bCanEverTick = false;

	// 컴포넌트 포인터 할당
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	// Default 속성 정의
	// Root에 SpringArm 부착
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.0f; // 스프링암의 길이
	SpringArmComp->bUsePawnControlRotation = true; // 컨트롤러를 회전할 때 스프링암도 같이 이동하도록 설정

	// 카메라 위치 조정
	SpringArmComp->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	// 우측 어깨 위로 카메라 위치 조정
	SpringArmComp->SocketOffset = FVector(0.0f, 0.0f, 35.0f);

	// 컴포넌트 포인터 할당
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	// Camera는 SpringArm에 부착
	// 두 번째 인자로 해당 컴포넌트의 특정 소켓 지정 가능
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName); // SocketName = SpringArm의 끝 부분
	CameraComp->bUsePawnControlRotation = false; // 스프링암만 회전, 카메라는 고정

	OverheadWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("OverheadWidget"));
	OverheadWidget->SetupAttachment(GetMesh());
	OverheadWidget->SetWidgetSpace(EWidgetSpace::Screen); // Widget 모드 Screen으로 설정

	// 속도 변수 Initialize
	MaxWalkingSpeed = 600.0f;
	CurrentWalkingSpeed = MaxWalkingSpeed;
	SprintSpeedMultiplier = 1.5f;
	SprintSpeed = MaxWalkingSpeed * SprintSpeedMultiplier;

	// 현재 캐릭터 걷는 속도 설정
	GetCharacterMovement()->MaxWalkSpeed = CurrentWalkingSpeed;

	// 체력 변수 초기화
	MaxHealth = 100.0f;
	Health = MaxHealth;

}

float ASpartaCharacter::GetHealth() const
{
	return Health;
}

void ASpartaCharacter::AddHealth(float Amount)
{
	Health = FMath::Clamp(Health + Amount, 0.0f, MaxHealth);
	UpdateOverheadHP();
}

void ASpartaCharacter::SlowDown(float DecelerationRate)
{
	CurrentWalkingSpeed = MaxWalkingSpeed * DecelerationRate;
	SprintSpeed *= DecelerationRate;

	UE_LOG(LogTemp, Warning, TEXT("New Walking Speed: %f"), CurrentWalkingSpeed);

	GetCharacterMovement()->MaxWalkSpeed = CurrentWalkingSpeed;
}

void ASpartaCharacter::RestoreSpeed()
{
	CurrentWalkingSpeed = MaxWalkingSpeed;
	SprintSpeed = MaxWalkingSpeed * SprintSpeedMultiplier;

	UE_LOG(LogTemp, Warning, TEXT("Restore Walking Speed: %f"), CurrentWalkingSpeed);

	GetCharacterMovement()->MaxWalkSpeed = CurrentWalkingSpeed;
}

void ASpartaCharacter::BeginPlay()
{
	Super::BeginPlay();
	UpdateOverheadHP();
}

void ASpartaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// EnhancedInputComponent 캐스팅
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// 현재 캐릭터를 조작하는 GetController()를 가져와
		// 직접 구현한 PlayerController 클래스로 캐스팅
		if (ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(GetController()))
		{
			// PlayerControlloer의 MoveAction 가져오기
			if (PlayerController->MoveAction)
			{
				// Input Action 바인딩 (이벤트와 함수 연결하는 핵심 코드)
				EnhancedInput->BindAction(
					PlayerController->MoveAction,	// IA 가져오기
					ETriggerEvent::Triggered,		// 트리거 이벤트
					this,
					&ASpartaCharacter::Move			// 호출되는 함수
				);
			}

			// 아래는 반복
			if (PlayerController->JumpAction)
			{
				EnhancedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::StartJump
				);

				EnhancedInput->BindAction(
					PlayerController->JumpAction,
					ETriggerEvent::Completed,		// 키 입력이 끝났을 때
					this,
					&ASpartaCharacter::StopJump
				);
			}

			if (PlayerController->LookAction)
			{
				EnhancedInput->BindAction(
					PlayerController->LookAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::Look
				);
			}

			if (PlayerController->SprintAction)
			{
				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::StartSprint
				);

				EnhancedInput->BindAction(
					PlayerController->SprintAction,
					ETriggerEvent::Completed,
					this,
					&ASpartaCharacter::StopSprint
				);
			}

			if (PlayerController->PauseAction)
			{
				EnhancedInput->BindAction(
					PlayerController->PauseAction,
					ETriggerEvent::Triggered,
					this,
					&ASpartaCharacter::Pause
				);
			}
		}
	}
}

float ASpartaCharacter::TakeDamage(
	float DamageAmount,		// 들어온 데미지
	FDamageEvent const& DamageEvent,
	AController* EventInstigator,
	AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);	// 방어, 회피 등을 고려한 실제 적용되는 데미지
	
	Health = FMath::Clamp(Health - DamageAmount, 0.0f, MaxHealth);
	UpdateOverheadHP();

	if (Health <= 0.0f)
	{
		OnDeath();
	}

	return ActualDamage;
}

void ASpartaCharacter::OnDeath()
{
	// 게임 종료 로직
	ASpartaGameState* SpartaGameState = GetWorld() ? GetWorld()->GetGameState<ASpartaGameState>() : nullptr;
	if (SpartaGameState)
	{
		SpartaGameState->OnGameOver();
	}
}

void ASpartaCharacter::UpdateOverheadHP()
{
	if (!OverheadWidget) return;
	
	UUserWidget* OverheadWidgetInstance = OverheadWidget->GetUserWidgetObject();
	if (!OverheadWidgetInstance) return;

	// HP Text Block 가져오기
	if (UProgressBar* HPBar = Cast<UProgressBar>(OverheadWidgetInstance->GetWidgetFromName(TEXT("HPBar"))))
	{
		// 체력 비율 계산
		float HPPercentage = (MaxHealth > 0) ? Health / MaxHealth : 0.0f;
		HPBar->SetPercent(HPPercentage);
	}
}

void ASpartaCharacter::Move(const FInputActionValue& value)
{
	// Controlloer 유효성 검사
	if (!Controller) return;

	// 입력 값 가져오기
	const FVector2D MoveInput = value.Get<FVector2D>();
	
	if (!FMath::IsNearlyZero(MoveInput.X))
	{
		AddMovementInput(GetActorForwardVector(), MoveInput.X);

		// 스켈레탈 메시 회전
		ApplyCharacterRotation(MoveInput.X * 90.0f - 90.0f);
	}

	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		AddMovementInput(GetActorRightVector(), MoveInput.Y);

		// 스켈레탈 메시 회전
		ApplyCharacterRotation(MoveInput.Y * 90.0f);	
	}
}

void ASpartaCharacter::ApplyCharacterRotation(float TargetYaw)
{
	if (!GetMesh()) return; // GetMesh()가 유효한지 확인

	// 스켈레탈 메쉬 기본 방향에 맞춰 보정
	TargetYaw += BaseRotationOffset.Rotator().Yaw;

	FRotator CurrentRotation = GetMesh()->GetRelativeRotation();

	// 최단 회전 방향 계산
	float DeltaYaw = FMath::UnwindDegrees(TargetYaw - CurrentRotation.Yaw);
	float NewYaw = FMath::FInterpTo(CurrentRotation.Yaw, CurrentRotation.Yaw + DeltaYaw, GetWorld()->GetDeltaSeconds(), 5.0f);

	FRotator NewRotation = CurrentRotation;
	NewRotation.Yaw = NewYaw;
	GetMesh()->SetRelativeRotation(NewRotation);
}

void ASpartaCharacter::StartJump(const FInputActionValue& value)
{
	// 입력 값 가져오기
	if (value.Get<bool>())
	{
		Jump();
	}
}

void ASpartaCharacter::StopJump(const FInputActionValue& value)
{
	if (!value.Get<bool>())
	{
		StopJumping();
	}
}

void ASpartaCharacter::Look(const FInputActionValue& value)
{
	FVector2D LookInput = value.Get<FVector2D>();

	AddControllerYawInput(LookInput.X);
	AddControllerPitchInput(LookInput.Y);
}

void ASpartaCharacter::StartSprint(const FInputActionValue& value)
{
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}
}

void ASpartaCharacter::StopSprint(const FInputActionValue& value)
{
	if (GetCharacterMovement())
	{
		GetCharacterMovement()->MaxWalkSpeed = CurrentWalkingSpeed;
	}
}

void ASpartaCharacter::Pause(const FInputActionValue& value)
{
	if (value.Get<bool>())
	{
		if (ASpartaPlayerController* SpartaPlayerController = Cast<ASpartaPlayerController>(GetController()))
		{
			SpartaPlayerController->TogglePauseMenu();
		}
	}
}
