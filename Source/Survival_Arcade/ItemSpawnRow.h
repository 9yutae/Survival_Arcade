#pragma once

#include "CoreMinimal.h"
#include "ItemSpawnRow.generated.h"

// ���� �󿡼� �ν��ϱ� ���� USTRUCT ����
// �������Ʈ Ÿ������ ����
USTRUCT(BlueprintType)
struct FItemSpawnRow : public FTableRowBase
{
	GENERATED_BODY()
public:
	// �� �࿡ �� ����(����) ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemName; // ������ �̸�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ItemClass; // ������ Ÿ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Spawnchance; // ���� Ȯ��

};
