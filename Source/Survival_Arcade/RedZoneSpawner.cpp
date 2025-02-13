#include "RedZoneSpawner.h"
#include "SpawnVolume.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "BombItem.h"
#include "SpartaPlayerController.h"

ARedZoneSpawner::ARedZoneSpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	// SpawnVolume ����
	TArray<AActor*> FoundVolumes;
	// ���� ���忡�� �ش��ϴ� Actor Ŭ������ ��� ������
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

	if (FoundVolumes.Num() > 0)
	{
		TargetSpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
	}

	// �⺻�� ����
	RedZoneStartTime = 15.0f;
	BombDropInterval = 5.0f;
	BombCountPerDrop = 3;
}

void ARedZoneSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	// ���� �ð� �� ������ ����
	GetWorld()->GetTimerManager().SetTimer(
		RedZoneTimerHandle,
		this,
		&ARedZoneSpawner::DropBombs,
		BombDropInterval,	// ��ź ���� �ֱ�
		true,				// �ݺ�
		RedZoneStartTime	// ù ��ź ���� �ð�
	);
}

void ARedZoneSpawner::DropBombs()
{
	if (!BombClass || !TargetSpawnVolume) return; // ��ź Ŭ������ �������� �ʾҴٸ� �������� ����.

	for (int32 i = 0; i < BombCountPerDrop; i++)
	{
		FVector SpawnLocation = TargetSpawnVolume->GetRandomPointInVolume();
		SpawnLocation.Z += 1000.0f;

		FRotator SpawnRotation = FRotator::ZeroRotator;

		// ��ź(����) ����
		ABombItem* SpawnedBomb = GetWorld()->SpawnActor<ABombItem>(BombClass, SpawnLocation, SpawnRotation);

		if (!SpawnedBomb)
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to spawn BombItem at location: %s"), *SpawnLocation.ToString());
		}
		else
		{
			if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
			{
				if (ASpartaPlayerController* SpartaPlayerController = Cast<ASpartaPlayerController>(PlayerController))
				{
					SpartaPlayerController->ShowRedzoneAlert();
				}
			}
		}
	}
}

