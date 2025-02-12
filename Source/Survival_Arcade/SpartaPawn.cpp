#include "SpartaPawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ASpartaPawn::ASpartaPawn()
{

	PrimaryActorTick.bCanEverTick = true;

	// ��Ʈ ������Ʈ �ʱ�ȭ
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	// ���̷�Ż �޽� ������Ʈ
	SkeletalMeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMeshComp->SetupAttachment(SceneRoot);

	// FObjectFinder �ȿ� �� Ÿ���� USkeletalMeshComponent�� �ƴ�
	// USkeletalMesh Ÿ��!
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Game/Resources/Characters/Meshes/SKM_Manny.SKM_Manny"));
	if (MeshAsset.Succeeded())
	{
		SkeletalMeshComp->SetSkeletalMesh(MeshAsset.Object);
	}

	// ���̷�Ż �޽� ������Ʈ Ʈ������ ��ȯ
	SkeletalMeshComp->SetRelativeLocation(FVector(0.0f, 0.0f, -87.0f));
	SkeletalMeshComp->SetRelativeRotation(FRotator(0.0f, -90.f, 0.0f));

	// ������Ʈ ������ �Ҵ�
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	// Default �Ӽ� ����
	// Root�� SpringArm ����
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 150.0f; // ���������� ����
	SpringArmComp->bUsePawnControlRotation = true; // ��Ʈ�ѷ��� ȸ���� �� �������ϵ� ���� �̵��ϵ��� ����

	// ī�޶� ��ġ ����
	SpringArmComp->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f));
	// ���� ��� ���� ī�޶� ��ġ ����
	SpringArmComp->SocketOffset = FVector(0.0f, 30.0f, 30.0f);

	// ������Ʈ ������ �Ҵ�
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	// Camera�� SpringArm�� ����
	// �� ��° ���ڷ� �ش� ������Ʈ�� Ư�� ���� ���� ����
	CameraComp->SetupAttachment(SpringArmComp, USpringArmComponent::SocketName); // SocketName = SpringArm�� �� �κ�
	CameraComp->bUsePawnControlRotation = false; // �������ϸ� ȸ��, ī�޶�� ����

	// �ʱ� �ӵ�
	Speed = 50.0f;

	// Ÿ�̸� �ʱ�ȭ
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
	
	// 3�� ���� ���� ��ȯ
	if (Timer >= 3.0f)
	{
		Timer -= 3.0f;
		Speed *= -1;
	}
	
	// x�� ����(�յ�)���� �̵�
	AddActorWorldOffset(FVector(Speed * DeltaTime, 0.0f, 0.0f));
	
}

void ASpartaPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
 
