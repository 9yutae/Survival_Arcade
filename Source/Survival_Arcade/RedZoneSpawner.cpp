#include "RedZoneSpawner.h"
#include "SpawnVolume.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "BombItem.h"
#include "SpartaPlayerController.h"

ARedZoneSpawner::ARedZoneSpawner()
{
	PrimaryActorTick.bCanEverTick = true;

	// SpawnVolume 설정
	TArray<AActor*> FoundVolumes;
	// 현재 월드에서 해당하는 Actor 클래스를 모두 가져옴
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

	if (FoundVolumes.Num() > 0)
	{
		TargetSpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
	}

	// 기본값 설정
	RedZoneStartTime = 15.0f;
	BombDropInterval = 5.0f;
	BombCountPerDrop = 3;
}

void ARedZoneSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	// 일정 시간 후 레드존 시작
	GetWorld()->GetTimerManager().SetTimer(
		RedZoneTimerHandle,
		this,
		&ARedZoneSpawner::DropBombs,
		BombDropInterval,	// 폭탄 투하 주기
		true,				// 반복
		RedZoneStartTime	// 첫 폭탄 투하 시간
	);
}

void ARedZoneSpawner::DropBombs()
{
	if (!BombClass || !TargetSpawnVolume) return; // 폭탄 클래스가 설정되지 않았다면 실행하지 않음.

	for (int32 i = 0; i < BombCountPerDrop; i++)
	{
		FVector SpawnLocation = TargetSpawnVolume->GetRandomPointInVolume();
		SpawnLocation.Z += 1000.0f;

		FRotator SpawnRotation = FRotator::ZeroRotator;

		// 폭탄(지뢰) 스폰
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

