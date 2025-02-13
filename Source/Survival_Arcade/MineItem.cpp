#include "MineItem.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

AMineItem::AMineItem()
{
	ExplosionDelay = 5.0f;
	ExplosionRadius = 300.0f;
	ExplosionDamage = 30.0f;
	ItemType = "Mine";
	bFallsFromSky = false;
	bHasExploded = false;

	ExplosionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionCollision"));
	ExplosionCollision->InitSphereRadius(ExplosionRadius);
	ExplosionCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	ExplosionCollision->SetupAttachment(Scene);
}

void AMineItem::BeginPlay()
{
	Super::BeginPlay();

	if (bFallsFromSky)
	{
		StaticMesh->SetSimulatePhysics(true);  // ���� ���� (�߷� ���� ����)
		StaticMesh->SetEnableGravity(true);
	}
}

void AMineItem::ActivateItem(AActor* Activator)
{
	if (bHasExploded) return;

	Super::ActivateItem(Activator);

	// ���� ���� -> Ÿ�̸� �Ŵ��� -> Ÿ�̸� �ڵ鷯
	GetWorld()->GetTimerManager().SetTimer( // ���� ������� Ÿ�̸� �ڵ鷯 ����
		ExplosionTimerHandle,  // Ÿ�� Ÿ�̸� �ڵ鷯
		this,	// ��� ���Ϳ�?
		&AMineItem::Explode, // ȣ���� �Լ�
		ExplosionDelay,	// ȣ���� �ð� (5�� ��)
		false // �ݺ� ����
	);

	bHasExploded = true;
}

void AMineItem::Explode()
{
	UParticleSystemComponent* Particle = nullptr;

	if (ExplosionParticle)
	{
		Particle = UGameplayStatics::SpawnEmitterAtLocation(
			GetWorld(),
			ExplosionParticle,
			GetActorLocation(),
			GetActorRotation(),
			false
		);
	}

	if (ExplosionSound)
	{
		UGameplayStatics::PlaySoundAtLocation(
			GetWorld(),
			ExplosionSound,
			GetActorLocation()
		);
	}

	TArray<AActor*> OverlappingActors;
	ExplosionCollision->GetOverlappingActors(OverlappingActors);

	for (AActor* Actor : OverlappingActors)
	{
		if (Actor && Actor->ActorHasTag("Player"))
		{
			UGameplayStatics::ApplyDamage(
				Actor,	// �������� ���� ����
				ExplosionDamage,	// ������ ��
				nullptr,	// �������� ������ ��ü
				this,	// �������� ���� ����
				UDamageType::StaticClass() // ������ Ÿ��::�⺻ Ÿ��
			);
		}
	}

	DestroyItem();

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
