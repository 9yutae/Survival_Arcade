#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "BushItem.generated.h"

UCLASS()
class SURVIVAL_ARCADE_API ABushItem : public ABaseItem
{
	GENERATED_BODY()
	
public:
	ABushItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bush")
	float DecelerationRate;

	virtual void ActivateItem(AActor* OtherActor) override;
	virtual void OnItemEndOverlap(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) override;
};
