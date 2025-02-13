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
		StaticMesh->SetSimulatePhysics(true);  // 물리 적용 (중력 영향 받음)
		StaticMesh->SetEnableGravity(true);
	}
}

void AMineItem::ActivateItem(AActor* Activator)
{
	if (bHasExploded) return;

	Super::ActivateItem(Activator);

	// 게임 월드 -> 타이머 매니저 -> 타이머 핸들러
	GetWorld()->GetTimerManager().SetTimer( // 위의 순서대로 타이머 핸들러 세팅
		ExplosionTimerHandle,  // 타겟 타이머 핸들러
		this,	// 어디 액터에?
		&AMineItem::Explode, // 호출할 함수
		ExplosionDelay,	// 호출할 시간 (5초 후)
		false // 반복 여부
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
				Actor,	// 데미지를 받을 액터
				ExplosionDamage,	// 데미지 양
				nullptr,	// 데미지를 유발한 주체
				this,	// 데미지를 입인 액터
				UDamageType::StaticClass() // 데미지 타입::기본 타입
			);
		}
	}

	DestroyItem();

	if (Particle)
	{
		// 일정 시간 후 파티클을 소멸시키는 타이머 생성
		FTimerHandle DestroyParticleTimerHandle;

		GetWorld()->GetTimerManager().SetTimer(
			DestroyParticleTimerHandle,
			[Particle]()
			{
				if (Particle && Particle->IsValidLowLevel()) // 유효성 체크
				{
					Particle->DestroyComponent();
				}
			},
			2.0f,
			false
		);
	}
}
