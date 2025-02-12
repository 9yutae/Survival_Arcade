#include "SpawnVolume.h"
#include "Components/BoxComponent.h"

ASpawnVolume::ASpawnVolume()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningBox"));
	SpawningBox->SetupAttachment(Scene);

	// ������ ���� �ʱ�ȭ
	MaxItemCount = 20;
	ItemCount = 0;

}

AActor* ASpawnVolume::SpawnRandomItem()
{
	// ���� Ȯ���� ������ ����
	if (FItemSpawnRow* SelectedRow = GetRandomItem())
	{
		// �������� Ŭ���� ��������
		if (UClass* ActualClass = SelectedRow->ItemClass.Get()) // TSoftClassPtr ����
		{
			// SpawnItem() ȣ��, ������ AActor ������ ����
			return SpawnItem(ActualClass);
		}
	}

	return nullptr;
}

FVector ASpawnVolume::GetRandomPointInVolum() const
{
	/* ���� ��ġ ���� ���ϱ�(Box ũ��)
	* GetScaledBoxExtent() : Box ������Ʈ ũ�⸦ �������� �Լ�
	* �߽ɿ��� �������� �Ÿ��� �����´�.
	*/
	FVector BoxExtent = SpawningBox->GetScaledBoxExtent();

	// �߽� ��ǥ ���ϱ�
	FVector BoxOrigin = SpawningBox->GetComponentLocation();
	
	// Box ���� �ȿ� ���� ��ġ ��ȯ
	return BoxOrigin + FVector(
		FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
		FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
		FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z)
	);
}

// ������ ����
AActor* ASpawnVolume::SpawnItem(TSubclassOf<AActor> ItemClass)
{
	if (!ItemClass) return nullptr; // ������ Ŭ������ �ƴ� ��� ��ȯ

	AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>( // AActor�� ���� Ŭ���� ����
		ItemClass,
		GetRandomPointInVolum(), // ���� ��ġ
		FRotator::ZeroRotator // ȸ���� (0, 0, 0)����
	);

	return SpawnedActor;
}

// ���� Ȯ���� ������ ����
FItemSpawnRow* ASpawnVolume::GetRandomItem() const
{
	// ������ ���̺� ��ȿ�� �˻�
	if (!ItemDataTable) return nullptr;
	
	// ������ ���̺��� ��� �� ��������
	TArray<FItemSpawnRow*> AllRows;
	static const FString ContextString(TEXT("ItemSpawnContext")); // ������ ����� ����� �޽��� (Ư�� ���� �� ���� ���� ���)

	ItemDataTable->GetAllRows(ContextString, AllRows);

	// ��ȿ�� �˻�
	if (AllRows.IsEmpty()) return nullptr;

	// Ȯ���� ���� ���ϱ�
	float TotalChance = 0.0f;
	for (const FItemSpawnRow* Row : AllRows)
	{
		if (Row)
		{
			TotalChance += Row->Spawnchance;

		}
	}

	// ������ Ŭ������ �̴� �˰����� '���� ������ �̱�'
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

	return nullptr; // �ڵ� ������ �ο�
}
