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

	// 이벤트 바인딩
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
	
	if (OtherActor && OtherActor->ActorHasTag("Player")) // Other Actor가 Player가 맞는지 확인 (nullptr이 아닌지도 확인)
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
		Particle = UGameplayStatics::SpawnEmitterAtLocation( // 지정된 위치나 회전에 파티클 효과 생성
			GetWorld(),			// 파티클 생성할 월드 정보
			PickupParticle,		// 지정한 파티클 에셋
			GetActorLocation(),	// 아이템의 월드 위치
			GetActorRotation(),	// 아이템의 회전 위치
			true				// 파티클 효과 종료 이후 메모리에서 자동 제거 여부
		);
	}

	if (PickupSound)
	{
		UGameplayStatics::PlaySoundAtLocation(	// 지정된 위치에서 사운드 재생
			GetWorld(),
			PickupSound,
			GetActorLocation()
		);
	}

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

FName ABaseItem::GetlItempType() const
{
	return ItemType;
}

void ABaseItem::DestroyItem()
{
	Destroy();
}
