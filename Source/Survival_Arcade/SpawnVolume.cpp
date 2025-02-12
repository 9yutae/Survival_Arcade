#include "SpawnVolume.h"
#include "Components/BoxComponent.h"

ASpawnVolume::ASpawnVolume()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningBox"));
	SpawningBox->SetupAttachment(Scene);

	// 아이템 개수 초기화
	MaxItemCount = 20;
	ItemCount = 0;

}

AActor* ASpawnVolume::SpawnRandomItem()
{
	// 랜덤 확률로 아이템 선택
	if (FItemSpawnRow* SelectedRow = GetRandomItem())
	{
		// 아이템의 클래스 가져오기
		if (UClass* ActualClass = SelectedRow->ItemClass.Get()) // TSoftClassPtr 형태
		{
			// SpawnItem() 호출, 스폰된 AActor 포인터 리턴
			return SpawnItem(ActualClass);
		}
	}

	return nullptr;
}

FVector ASpawnVolume::GetRandomPointInVolum() const
{
	/* 랜덤 위치 범위 구하기(Box 크기)
	* GetScaledBoxExtent() : Box 컴포넌트 크기를 가져오는 함수
	* 중심에서 끝까지의 거리를 가져온다.
	*/
	FVector BoxExtent = SpawningBox->GetScaledBoxExtent();

	// 중심 좌표 구하기
	FVector BoxOrigin = SpawningBox->GetComponentLocation();
	
	// Box 범위 안에 랜덤 위치 반환
	return BoxOrigin + FVector(
		FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
		FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
		FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z)
	);
}

// 아이템 스폰
AActor* ASpawnVolume::SpawnItem(TSubclassOf<AActor> ItemClass)
{
	if (!ItemClass) return nullptr; // 아이템 클래스가 아닐 경우 반환

	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>( // AActor의 하위 클래스 포함
		ItemClass,
		GetRandomPointInVolum(), // 랜덤 위치
		FRotator::ZeroRotator // 회전은 (0, 0, 0)으로
	);

	return SpawnedActor;
}

// 랜덤 확률로 아이템 선택
FItemSpawnRow* ASpawnVolume::GetRandomItem() const
{
	// 데이터 테이블 유효성 검사
	if (!ItemDataTable) return nullptr;
	
	// 데이터 테이블의 모든 행 가져오기
	TArray<FItemSpawnRow*> AllRows;
	static const FString ContextString(TEXT("ItemSpawnContext")); // 오류를 대비한 디버그 메시지 (특정 행을 못 가져 왔을 경우)

	ItemDataTable->GetAllRows(ContextString, AllRows);

	// 유효성 검사
	if (AllRows.IsEmpty()) return nullptr;

	// 확률의 총합 구하기
	float TotalChance = 0.0f;
	for (const FItemSpawnRow* Row : AllRows)
	{
		if (Row)
		{
			TotalChance += Row->Spawnchance;

		}
	}

	// 아이템 클래스를 뽑는 알고리즘은 '누적 랜덤값 뽑기'
	const float RandValue = FMath::FRandRange(0.0f, TotalChance);
	float AccumulateChance = 0.0f;

	for (FItemSpawnRow* Row : AllRows)
	{
		AccumulateChance += Row->Spawnchance;
		if (RandValue <= AccumulateChance)
		{
			return Row;
		}
	}

	return nullptr; // 코드 안정성 부여
}
