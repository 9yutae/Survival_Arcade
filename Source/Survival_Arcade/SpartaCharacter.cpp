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
	// Tick �Լ� ��Ȱ��ȭ
	PrimaryActorTick.bCanEverTick = false;

	// ������Ʈ ������ �Ҵ�
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	// Default �Ӽ� ����
	// Root�� SpringArm ����
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 300.0f; // ���������� ����
	SpringArmComp->bUsePawnControlRotation = true; // ��Ʈ�ѷ��� ȸ���� �� �������ϵ� ���� �̵��ϵ��� ����

	// ī�޶� ��ġ ����
	SpringArmComp->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	// ���� ��� ���� ī�޶� ��ġ ����
	SpringArmComp->SocketOffset = FVector(0.0f, 0.0f, 35.0f);

	// ������Ʈ ������ �Ҵ�
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	// Camera�� SpringArm�� ����
	// �� ��° ���ڷ� �ش� ������Ʈ�� Ư�� ���� ���� ����
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName); // SocketName = SpringArm�� �� �κ�
	CameraComp->bUsePawnControlRotation = false; // �������ϸ� ȸ��, ī�޶�� ����

	OverheadWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("OverheadWidget"));
	OverheadWidget->SetupAttachment(GetMesh());
	OverheadWidget->SetWidgetSpace(EWidgetSpace::Screen); // Widget ��� Screen���� ����

	// �ӵ� ���� Initialize
	MaxWalkingSpeed = 600.0f;
	CurrentWalkingSpeed = MaxWalkingSpeed;
	SprintSpeedMultiplier = 1.5f;
	SprintSpeed = MaxWalkingSpeed * SprintSpeedMultiplier;

	// ���� ĳ���� �ȴ� �ӵ� ����
	GetCharacterMovement()->MaxWalkSpeed = CurrentWalkingSpeed;

	// ü�� ���� �ʱ�ȭ
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

	// EnhancedInputComponent ĳ����
	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// ���� ĳ���͸� �����ϴ� GetController()�� ������
		// ���� ������ PlayerController Ŭ������ ĳ����
		if (ASpartaPlayerController* PlayerController = Cast<ASpartaPlayerController>(GetController()))
		{
			// PlayerControlloer�� MoveAction ��������
			if (PlayerController->MoveAction)
			{
				// Input Action ���ε� (�̺�Ʈ�� �Լ� �����ϴ� �ٽ� �ڵ�)
				EnhancedInput->BindAction(
					PlayerController->MoveAction,	// IA ��������
					ETriggerEvent::Triggered,		// Ʈ���� �̺�Ʈ
					this,
					&ASpartaCharacter::Move			// ȣ��Ǵ� �Լ�
				);
			}

			// �Ʒ��� �ݺ�
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
					ETriggerEvent::Completed,		// Ű �Է��� ������ ��
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
	float DamageAmount,		// ���� ������
	FDamageEvent const& DamageEvent,
	AController* EventInstigator,
	AActor* DamageCauser)
{
	float ActualDamage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);	// ���, ȸ�� ���� ����� ���� ����Ǵ� ������
	
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
	// ���� ���� ����
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

	// HP Text Block ��������
	if (UProgressBar* HPBar = Cast<UProgressBar>(OverheadWidgetInstance->GetWidgetFromName(TEXT("HPBar"))))
	{
		// ü�� ���� ���
		float HPPercentage = (MaxHealth > 0) ? Health / MaxHealth : 0.0f;
		HPBar->SetPercent(HPPercentage);
	}
}

void ASpartaCharacter::Move(const FInputActionValue& value)
{
	// Controlloer ��ȿ�� �˻�
	if (!Controller) return;

	// �Է� �� ��������
	const FVector2D MoveInput = value.Get<FVector2D>();
	
	if (!FMath::IsNearlyZero(MoveInput.X))
	{
		AddMovementInput(GetActorForwardVector(), MoveInput.X);

		// ���̷�Ż �޽� ȸ��
		ApplyCharacterRotation(MoveInput.X * 90.0f - 90.0f);
	}

	if (!FMath::IsNearlyZero(MoveInput.Y))
	{
		AddMovementInput(GetActorRightVector(), MoveInput.Y);

		// ���̷�Ż �޽� ȸ��
		ApplyCharacterRotation(MoveInput.Y * 90.0f);	
	}
}

void ASpartaCharacter::ApplyCharacterRotation(float TargetYaw)
{
	if (!GetMesh()) return; // GetMesh()�� ��ȿ���� Ȯ��

	// ���̷�Ż �޽� �⺻ ���⿡ ���� ����
	TargetYaw += BaseRotationOffset.Rotator().Yaw;

	FRotator CurrentRotation = GetMesh()->GetRelativeRotation();

	// �ִ� ȸ�� ���� ���
	float DeltaYaw = FMath::UnwindDegrees(TargetYaw - CurrentRotation.Yaw);
	float NewYaw = FMath::FInterpTo(CurrentRotation.Yaw, CurrentRotation.Yaw + DeltaYaw, GetWorld()->GetDeltaSeconds(), 5.0f);

	FRotator NewRotation = CurrentRotation;
	NewRotation.Yaw = NewYaw;
	GetMesh()->SetRelativeRotation(NewRotation);
}

void ASpartaCharacter::StartJump(const FInputActionValue& value)
{
	// �Է� �� ��������
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
