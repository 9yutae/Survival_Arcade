#include "SpartaPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ASpartaPawn::ASpartaPawn()
{

	PrimaryActorTick.bCanEverTick = true;

	// 루트 컴포넌트 초기화
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// 스켈레탈 메시 컴포넌트
	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMeshComp->SetupAttachment(SceneRoot);

	// FObjectFinder 안에 들어갈 타입은 USkeletalMeshComponent가 아닌
	// USkeletalMesh 타입!
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Game/Resources/Characters/Meshes/SKM_Manny.SKM_Manny"));
	if (MeshAsset.Succeeded())
	{
		SkeletalMeshComp->SetSkeletalMesh(MeshAsset.Object);
	}

	// 스켈레탈 메시 컴포넌트 트랜스폼 변환
	SkeletalMeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, -87.0f));
	SkeletalMeshComp->SetRelativeRotation(FRotator(0.0f, -90.f, 0.0f));

	// 컴포넌트 포인터 할당
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	// Default 속성 정의
	// Root에 SpringArm 부착
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 150.0f; // 스프링암의 길이
	SpringArmComp->bUsePawnControlRotation = true; // 컨트롤러를 회전할 때 스프링암도 같이 이동하도록 설정

	// 카메라 위치 조정
	SpringArmComp->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	// 우측 어깨 위로 카메라 위치 조정
	SpringArmComp->SocketOffset = FVector(0.0f, 30.0f, 30.0f);

	// 컴포넌트 포인터 할당
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	// Camera는 SpringArm에 부착
	// 두 번째 인자로 해당 컴포넌트의 특정 소켓 지정 가능
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName); // SocketName = SpringArm의 끝 부분
	CameraComp->bUsePawnControlRotation = false; // 스프링암만 회전, 카메라는 고정

	// 초기 속도
	Speed = 50.0f;

	// 타이머 초기화
	Timer = 0.0f;
	
}

void ASpartaPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpartaPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timer += DeltaTime;
	
	// 3초 마다 방향 전환
	if (Timer >= 3.0f)
	{
		Timer -= 3.0f;
		Speed *= -1;
	}
	
	// x축 방향(앞뒤)으로 이동
	AddActorWorldOffset(FVector(Speed * DeltaTime, 0.0f, 0.0f));
	
}

void ASpartaPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
 
