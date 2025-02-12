#pragma once

#include "CoreMinimal.h"
#include "ItemSpawnRow.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

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

	// ������ ������ ���̺� ��������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	UDataTable* ItemDataTable;

	// ������ ����
	UFUNCTION(BlueprintCallable, Category = "Spawning")
	AActor* SpawnRandomItem();

	// �ִ� ���� ������ ������ ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawning")
	int32 MaxItemCount;

	// ������ ��ġ�� ��ȯ�ϱ� ���� FVector
	FVector GetRandomPointInVolum() const;
	// ������ Ŭ������ �������� �����ϴ� �Լ�
	AActor* SpawnItem(TSubclassOf<AActor> ItemClass); // TSubclassOf : Actor�� ���� Ŭ�������� �����Ͽ� ���� (Actor�� �ƴϸ� ����)
	// ���� Ȯ���� ������ ����
	FItemSpawnRow* GetRandomItem() const;
	// ������ ������ ����
	int32 ItemCount;

};
