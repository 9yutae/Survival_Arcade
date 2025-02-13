#include "SpartaGameState.h"
#include "SpartaGameInstance.h"
#include "SpartaPlayerController.h"
#include "kismet/GameplayStatics.h"
#include "SpawnVolume.h"
#include "BaseItem.h"
#include "CoinItem.h"
#include "RedZoneSpawner.h"
#include "Components/TextBlock.h"
#include "Blueprint/UserWidget.h"

ASpartaGameState::ASpartaGameState()
{
	Score = 0;

	// 전체 초기화
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;

	// 타이머 설정
	WaveDuration = 30.0f;
	// 현재 레벨 Index 설정
	CurrentLevelIndex = 0;
	// 최대 레벨 설정
	MaxLevel = 3;
	// 최대 웨이브 설정
	MaxWave = 3;
}

void ASpartaGameState::BeginPlay()
{
	Super::BeginPlay();

	StartLevel();

	GetWorldTimerManager().SetTimer(  // 0.1초마다 HUD Update
		HUDUpdateTimerHandle,
		this,
		&ASpartaGameState::UpdateHUD,
		0.1f,
		true
	);
}

int32 ASpartaGameState::GetScore() const
{
	return Score;
}

void ASpartaGameState::AddScore(int32 Amount)
{
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(GameInstance);
		if (SpartaGameInstance)
		{
			SpartaGameInstance->AddToScore(Amount);
		}
	}
}

void ASpartaGameState::OnGameOver()
{
	// Main Menu로 전환
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (ASpartaPlayerController* SpartaPlayerController = Cast<ASpartaPlayerController>(PlayerController))
		{
			SpartaPlayerController->SetPause(true);		// 게임 종료 시, Pause
			SpartaPlayerController->ShowGameOverMenu(); // 재시작이므로, true를 인자로!
		}
	}
}

void ASpartaGameState::StartLevel()
{
	// 메뉴 UI에서 HUD로 전환
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (ASpartaPlayerController* SpartaPlayerController = Cast<ASpartaPlayerController>(PlayerController))
		{
			SpartaPlayerController->ShowGameHUD();
		}
	}

	if (UGameInstance* GameInstance = GetGameInstance())
	{
		USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(GameInstance);
		if (SpartaGameInstance)
		{
			CurrentLevelIndex = SpartaGameInstance->CurrentLevelIndex;
		}
	}

	// 해당 레벨을 불러올 때 초기화
	CurrentWaveIndex = 0;

	StartWave();
}

void ASpartaGameState::StartWave()
{
	// 이전 웨이브 아이템 삭제
	TArray<AActor*> ExistingItems;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), ExistingItems);

	for (AActor* Item : ExistingItems)
	{
		if (Item && (Item->IsA(ACoinItem::StaticClass()) || Item->IsA(ABaseItem::StaticClass())))
		{
			Item->Destroy(); // 기존 아이템 삭제
		}
	}

	// 기존 데이터초기화
	Score = 0;
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;

	TArray<AActor*> FoundVolumes;
	// 현재 월드에서 해당하는 Actor 클래스를 모두 가져옴
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

	const int32 ItemToSpawn = 30 + CurrentWaveIndex * 10; // 스폰할 아이템 개수 설정

	// Coin Item 스폰
	for (int32 i = 0; i < ItemToSpawn; i++)
	{
		if (FoundVolumes.Num() > 0)
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
			if (SpawnVolume)
			{
				// 스폰된 아이템 Actor 가져오기
				AActor* SpawnedActor = SpawnVolume->SpawnRandomItem();

				// 스폰된 Actor가 Coin 아이템인지 확인
				if (SpawnedActor && SpawnedActor->IsA(ACoinItem::StaticClass()))
				{
					SpawnedCoinCount++;
				}
			}
		}
	}

	// 상위 Wave 아이템 추가
	if (CurrentWaveIndex > 0) {
		for (int32 i = 0; i < ItemToSpawn * CurrentWaveIndex * 1.5f; i++)
		{
			if (FoundVolumes.Num() > 0)
			{
				if (ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]))
				{
					SpawnVolume->SpawnBushItem();
				}
			} 
		}
	}

	if (CurrentWaveIndex > 1) {
		FVector SpawnLocation = FVector(0.0f, 0.0f, 0.0f); // RedZoneSpawner를 (0,0,0)에 배치
		FRotator SpawnRotation = FRotator::ZeroRotator;

		ARedZoneSpawner* RedZoneSpawner = GetWorld()->SpawnActor<ARedZoneSpawner>(RedZoneSpawnerClass, SpawnLocation, SpawnRotation);
	}

	UE_LOG(LogTemp, Warning, TEXT("Wave %d Started!"), CurrentWaveIndex + 1);

	// 타이머 세팅
	GetWorldTimerManager().SetTimer(
		WaveTimerHandle,
		this,
		&ASpartaGameState::OnWaveTimeUp, // 호출될 함수 지정
		WaveDuration,	// 웨이브 지속 시간 설정
		false	// 타이머 반복 여부
	);
}

void ASpartaGameState::OnWaveTimeUp() // 시간 초과
{
	EndWave();	// 레벨 종료
}

void ASpartaGameState::OnCoinCollected()
{
	CollectedCoinCount++;

	if (SpawnedCoinCount > 0 && CollectedCoinCount >= SpawnedCoinCount)
	{
		EndWave();
	}
}

void ASpartaGameState::EndLevel()
{
	// 타이머 초기화
	// GetWorldTimerManager().ClearTimer(WaveTimerHandle);
	GetWorldTimerManager().ClearAllTimersForObject(this);

	if (UGameInstance* GameInstance = GetGameInstance())
	{
		USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(GameInstance);
		if (SpartaGameInstance)
		{
			CurrentLevelIndex++;
			SpartaGameInstance->CurrentLevelIndex = CurrentLevelIndex;
		}
	}

	// 최대 레벨 초과 시 게임 종료
	if (CurrentLevelIndex >= MaxLevel)
	{
		OnGameOver();
		return;
	}
	
	// 다음 레벨 입장
	if (LevelMapNames.IsValidIndex(CurrentLevelIndex))
	{
		UGameplayStatics::OpenLevel(GetWorld(), LevelMapNames[CurrentLevelIndex]);
	}
	else
	{
		OnGameOver();
	}
}

void ASpartaGameState::EndWave()
{
	// 타이머 초기화
	GetWorldTimerManager().ClearTimer(WaveTimerHandle);

	if (UGameInstance* GameInstance = GetGameInstance())
	{
		USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(GameInstance);
		if (SpartaGameInstance)
		{
			AddScore(Score);
			CurrentWaveIndex++;
			SpartaGameInstance->CurrentLevelIndex = CurrentLevelIndex;
		}
	}

	// 최대 웨이브 초과 시 다음 레벨
	if (CurrentWaveIndex >= MaxWave)
	{
		EndLevel();
		return;
	}

	// 다음 웨이브 입장
	if (LevelMapNames.IsValidIndex(CurrentLevelIndex))
	{
		StartWave();
	}
	else
	{
		OnGameOver();
	}
}

void ASpartaGameState::UpdateHUD()
{
	// PlayerController에서 HUDWidget 가져오기
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (ASpartaPlayerController* SpartaPlayerController = Cast<ASpartaPlayerController>(PlayerController))
		{
			if (UUserWidget* HUDWidget = SpartaPlayerController->GetHUDWidget())
			{
				// 시간
				if (UTextBlock* TimeText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("TimeText"))))
				{
					// WorldTimerManager에서 남은 시간 가져오기
					float RemainingTime = GetWorldTimerManager().GetTimerRemaining(WaveTimerHandle);
					// 출력
					TimeText->SetText(FText::FromString(FString::Printf(TEXT("Time: %.1f"), RemainingTime)));
				}

				// 점수
				if (UTextBlock* ScoreText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("ScoreText"))))
				{
					// GameInstance에 Total Score 저장 -> GameInstance 가져오기
					if (UGameInstance* GameInstance = GetGameInstance())
					{
						USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(GameInstance);
						if (SpartaGameInstance)
						{
							// GameInstance에서 Total Score 가져와서 출력
							ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), SpartaGameInstance->TotalScore)));
						}
					}					
				}

				// 레벨
				if (UTextBlock* LevelText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("LevelText"))))
				{
					// 레벨 Index는 GameState에서 관리
					LevelText->SetText(FText::FromString(FString::Printf(TEXT("Level: %d"), CurrentLevelIndex + 1)));
				}

				if (UTextBlock* WaveText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("WaveText"))))
				{
					// 레벨 Index는 GameState에서 관리
					WaveText->SetText(FText::FromString(FString::Printf(TEXT("Wave: %d"), CurrentWaveIndex + 1)));
				}
			}
		}
	}
}
