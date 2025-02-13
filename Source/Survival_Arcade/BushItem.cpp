#include "BushItem.h"
#include "SpartaCharacter.h"

ABushItem::ABushItem()
{
    if (StaticMesh)
    {
        StaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
        StaticMesh->SetGenerateOverlapEvents(false);
    }

    DecelerationRate = 0.5f;
    ItemType = "Debuff";
}

void ABushItem::ActivateItem(AActor* OtherActor)
{
    if (OtherActor && OtherActor->ActorHasTag("Player"))
    {
        if (ASpartaCharacter* PlayerCharacter = Cast<ASpartaCharacter>(OtherActor))
        {
            UE_LOG(LogTemp, Warning, TEXT("Player has overlapped with SlowingItem"));
            PlayerCharacter->SlowDown(DecelerationRate);
        }
    }
}

void ABushItem::OnItemEndOverlap(
    UPrimitiveComponent* OverlappedComp,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex)
{
    if (OtherActor && OtherActor->ActorHasTag("Player"))
    {
        if (ASpartaCharacter* PlayerCharacter = Cast<ASpartaCharacter>(OtherActor))
        {
            UE_LOG(LogTemp, Warning, TEXT("Player left   SlowingItem"));
            PlayerCharacter->RestoreSpeed();
        }
    }
}
