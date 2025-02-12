#include "BaseItem.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision)"));
	Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	Collision->SetupAttachment(Scene);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Collision);

	// �̺�Ʈ ���ε�
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ABaseItem::OnItemOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &ABaseItem::OnItemEndOverlap);
}

void ABaseItem::OnItemOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, 
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	
	if (OtherActor && OtherActor->ActorHasTag("Player")) // Other Actor�� Player�� �´��� Ȯ�� (nullptr�� �ƴ����� Ȯ��)
	{
		ActivateItem(OtherActor);
	}
}

void ABaseItem::OnItemEndOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
}

void ABaseItem::ActivateItem(AActor* Activator)
{
	UParticleSystemComponent* Particle = nullptr;

	if (PickupParticle)
	{
		Particle = UGameplayStatics::SpawnEmitterAtLocation( // ������ ��ġ�� ȸ���� ��ƼŬ ȿ�� ����
			GetWorld(),			// ��ƼŬ ������ ���� ����
			PickupParticle,		// ������ ��ƼŬ ����
			GetActorLocation(),	// �������� ���� ��ġ
			GetActorRotation(),	// �������� ȸ�� ��ġ
			true				// ��ƼŬ ȿ�� ���� ���� �޸𸮿��� �ڵ� ���� ����
		);
	}

	if (PickupSound)
	{
		UGameplayStatics::PlaySoundAtLocation(	// ������ ��ġ���� ���� ���
			GetWorld(),
			PickupSound,
			GetActorLocation()
		);
	}

	if (Particle)
	{
		// ���� �ð� �� ��ƼŬ�� �Ҹ��Ű�� Ÿ�̸� ����
		FTimerHandle DestroyParticleTimerHandle;

		GetWorld()->GetTimerManager().SetTimer(
			DestroyParticleTimerHandle,
			[Particle]()
			{
				if (Particle && Particle->IsValidLowLevel()) // ��ȿ�� üũ
				{
					Particle->DestroyComponent();
				}
			},
			2.0f,
			false
		);
	}
}

FName ABaseItem::GetlItempType() const
{
	return ItemType;
}

void ABaseItem::DestroyItem()
{
	Destroy();
}
