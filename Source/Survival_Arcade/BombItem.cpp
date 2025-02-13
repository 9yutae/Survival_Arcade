#include "BombItem.h"
#include "Spartacharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/DamageType.h"

ABombItem::ABombItem()
{
	ExplosionRadius = 1000.0f;
	ExplosionDamage = 70.0f;

	BombMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BombMesh"));
	SetRootComponent(BombMesh);

	// 충돌 이벤트 바인딩
	BombMesh->OnComponentHit.AddDynamic(this, &ABombItem::OnHit);
	BombMesh->SetSimulatePhysics(true);
	BombMesh->SetEnableGravity(true);
    BombMesh->SetCollisionProfileName(TEXT("BlockAllDynamic"));

    BombMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    BombMesh->SetCollisionObjectType(ECC_PhysicsBody);
    BombMesh->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Ignore);
    BombMesh->SetCollisionResponseToAllChannels(ECR_Block);
    BombMesh->SetNotifyRigidBodyCollision(true); // 충돌 알림 활성화
}

void ABombItem::OnHit(
	UPrimitiveComponent* HitComp, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	FVector NormalImpulse, 
	const FHitResult& Hit)
{
	if (OtherActor && OtherActor->ActorHasTag(TEXT("Floor")))
	{
        UE_LOG(LogTemp, Warning, TEXT("Bomb Hit the Floor!"));
		Explode();
	}
}

void ABombItem::Explode()
{
    // 폭발 효과 생성
    if (ExplosionEffect)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
    }

    // 폭발 사운드 재생
    if (ExplosionSound)
    {
        UGameplayStatics::PlaySoundAtLocation(GetWorld(), ExplosionSound, GetActorLocation());
    }

    TArray<AActor*> OverlappingActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpartaCharacter::StaticClass(), OverlappingActors);

    for (AActor* Actor : OverlappingActors)
    {
        if (Actor && Actor->ActorHasTag("Player"))
        {
            float DistanceToPlayer = FVector::Dist(Actor->GetActorLocation(), GetActorLocation());

            if (DistanceToPlayer <= ExplosionRadius)
            {
                UGameplayStatics::ApplyDamage(
                    Actor,                 // 데미지를 받을 액터
                    ExplosionDamage,       // 데미지 양
                    nullptr,               // 데미지를 유발한 주체
                    this,                  // 데미지를 입힌 액터 (폭탄)
                    UDamageType::StaticClass() // 기본 데미지 타입
                );
            }
        }
    }

    // 폭발 후 제거
    Destroy();
}
