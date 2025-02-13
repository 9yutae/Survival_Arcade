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

	// �浹 �̺�Ʈ ���ε�
	BombMesh->OnComponentHit.AddDynamic(this, &ABombItem::OnHit);
	BombMesh->SetSimulatePhysics(true);
	BombMesh->SetEnableGravity(true);
    BombMesh->SetCollisionProfileName(TEXT("BlockAllDynamic"));

    BombMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
    BombMesh->SetCollisionObjectType(ECC_PhysicsBody);
    BombMesh->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Ignore);
    BombMesh->SetCollisionResponseToAllChannels(ECR_Block);
    BombMesh->SetNotifyRigidBodyCollision(true); // �浹 �˸� Ȱ��ȭ
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
    // ���� ȿ�� ����
    if (ExplosionEffect)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionEffect, GetActorLocation());
    }

    // ���� ���� ���
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
                    Actor,                 // �������� ���� ����
                    ExplosionDamage,       // ������ ��
                    nullptr,               // �������� ������ ��ü
                    this,                  // �������� ���� ���� (��ź)
                    UDamageType::StaticClass() // �⺻ ������ Ÿ��
                );
            }
        }
    }

    // ���� �� ����
    Destroy();
}
