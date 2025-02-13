#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RedZoneSpawner.generated.h"

class ASpawnVolume;
class ABombItem;

UCLASS()
class SURVIVAL_ARCADE_API ARedZoneSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ARedZoneSpawner();

protected:
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "RedZone")
	float RedZoneStartTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RedZone")
	float BombDropInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RedZone")
	int32 BombCountPerDrop;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RedZone")
	TSubclassOf<class ABombItem> BombClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RedZone")
	ASpawnVolume* TargetSpawnVolume;

	FTimerHandle RedZoneTimerHandle;

	void DropBombs();

};
