#pragma once

#include "CoreMinimal.h"
#include "ItemSpawnRow.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;
class ABushItem;

UCLASS()
class SURVIVAL_ARCADE_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	USceneComponent* Scene;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
	UBoxComponent* SpawningBox;

	// 아이템 데이터 테이블 가져오기
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	UDataTable* ItemDataTable;

	// 아이템 스폰
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	AActor* SpawnRandomItem();
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	AActor* SpawnBushItem();

	// 무작위 위치에 소환하기 위한 FVector
	FVector GetRandomPointInVolume() const;
	// 지정된 클래스의 아이템을 스폰하는 함수
	AActor* SpawnItem(TSubclassOf<AActor> ItemClass); // TSubclassOf : Actor의 하위 클래스까지 포함하여 지정 (Actor가 아니면 오류)
	// 랜덤 확률로 아이템 선택
	FItemSpawnRow* GetRandomItem() const;
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<ABushItem> ABushItemClass; // 올바른 클래스 타입 지정

};
