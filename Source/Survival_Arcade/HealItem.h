#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "HealItem.generated.h"

UCLASS()
class SURVIVAL_ARCADE_API AHealItem : public ABaseItem
{
	GENERATED_BODY()
	
public:
	AHealItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 HealAmount;

	virtual void ActivateItem(AActor* Activator) override;

};
