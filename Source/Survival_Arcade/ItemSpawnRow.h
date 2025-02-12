#pragma once

#include "CoreMinimal.h"
#include "ItemSpawnRow.generated.h"

// 엔진 상에서 인식하기 위해 USTRUCT 선언
// 블루프린트 타입으로 선언
USTRUCT(BlueprintType)
struct FItemSpawnRow : public FTableRowBase
{
	GENERATED_BODY()
public:
	// 한 행에 들어갈 정보(변수) 선언
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName ItemName; // 아이템 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> ItemClass; // 아이템 타입
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Spawnchance; // 생성 확률

};
