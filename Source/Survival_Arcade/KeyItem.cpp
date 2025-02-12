#include "KeyItem.h"
#include <iostream>

AKeyItem::AKeyItem()
{
	ItemType = "Key";
}

void AKeyItem::OnItemOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Display, TEXT("Key collected!"));

}

void AKeyItem::ActivateItem(AActor* Activator)
{
	UE_LOG(LogTemp, Display, TEXT("Key used to unlock the door!"));
	DestroyItem();
}
