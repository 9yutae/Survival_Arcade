#include "HealItem.h"
#include "SpartaCharacter.h"

AHealItem::AHealItem()
{
	HealAmount = 20.f;
	ItemType = "Heal";
}

void AHealItem::ActivateItem(AActor* Activator)
{
	Super::ActivateItem(Activator);

	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (ASpartaCharacter* PlayerCharacter = Cast<ASpartaCharacter>(Activator))
		{
			PlayerCharacter->AddHealth(HealAmount);
		}

		DestroyItem();
	}
}
