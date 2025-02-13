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

	// ��ü �ʱ�ȭ
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;

	// Ÿ�̸� ����
	WaveDuration = 30.0f;
	// ���� ���� Index ����
	CurrentLevelIndex = 0;
	// �ִ� ���� ����
	MaxLevel = 3;
	// �ִ� ���̺� ����
	MaxWave = 3;
}

void ASpartaGameState::BeginPlay()
{
	Super::BeginPlay();

	StartLevel();

	GetWorldTimerManager().SetTimer(  // 0.1�ʸ��� HUD Update
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
	// Main Menu�� ��ȯ
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (ASpartaPlayerController* SpartaPlayerController = Cast<ASpartaPlayerController>(PlayerController))
		{
			SpartaPlayerController->SetPause(true);		// ���� ���� ��, Pause
			SpartaPlayerController->ShowGameOverMenu(); // ������̹Ƿ�, true�� ���ڷ�!
		}
	}
}

void ASpartaGameState::StartLevel()
{
	// �޴� UI���� HUD�� ��ȯ
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

	// �ش� ������ �ҷ��� �� �ʱ�ȭ
	CurrentWaveIndex = 0;

	StartWave();
}

void ASpartaGameState::StartWave()
{
	// ���� ���̺� ������ ����
	TArray<AActor*> ExistingItems;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), ExistingItems);

	for (AActor* Item : ExistingItems)
	{
		if (Item && (Item->IsA(ACoinItem::StaticClass()) || Item->IsA(ABaseItem::StaticClass())))
		{
			Item->Destroy(); // ���� ������ ����
		}
	}

	// ���� �������ʱ�ȭ
	Score = 0;
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;

	TArray<AActor*> FoundVolumes;
	// ���� ���忡�� �ش��ϴ� Actor Ŭ������ ��� ������
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

	const int32 ItemToSpawn = 30 + CurrentWaveIndex * 10; // ������ ������ ���� ����

	// Coin Item ����
	for (int32 i = 0; i < ItemToSpawn; i++)
	{
		if (FoundVolumes.Num() > 0)
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
			if (SpawnVolume)
			{
				// ������ ������ Actor ��������
				AActor* SpawnedActor = SpawnVolume->SpawnRandomItem();

				// ������ Actor�� Coin ���������� Ȯ��
				if (SpawnedActor && SpawnedActor->IsA(ACoinItem::StaticClass()))
				{
					SpawnedCoinCount++;
				}
			}
		}
	}

	// ���� Wave ������ �߰�
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
		FVector SpawnLocation = FVector(0.0f, 0.0f, 0.0f); // RedZoneSpawner�� (0,0,0)�� ��ġ
		FRotator SpawnRotation = FRotator::ZeroRotator;

		ARedZoneSpawner* RedZoneSpawner = GetWorld()->SpawnActor<ARedZoneSpawner>(RedZoneSpawnerClass, SpawnLocation, SpawnRotation);
	}

	UE_LOG(LogTemp, Warning, TEXT("Wave %d Started!"), CurrentWaveIndex + 1);

	// Ÿ�̸� ����
	GetWorldTimerManager().SetTimer(
		WaveTimerHandle,
		this,
		&ASpartaGameState::OnWaveTimeUp, // ȣ��� �Լ� ����
		WaveDuration,	// ���̺� ���� �ð� ����
		false	// Ÿ�̸� �ݺ� ����
	);
}

void ASpartaGameState::OnWaveTimeUp() // �ð� �ʰ�
{
	EndWave();	// ���� ����
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
	// Ÿ�̸� �ʱ�ȭ
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

	// �ִ� ���� �ʰ� �� ���� ����
	if (CurrentLevelIndex >= MaxLevel)
	{
		OnGameOver();
		return;
	}
	
	// ���� ���� ����
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
	// Ÿ�̸� �ʱ�ȭ
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

	// �ִ� ���̺� �ʰ� �� ���� ����
	if (CurrentWaveIndex >= MaxWave)
	{
		EndLevel();
		return;
	}

	// ���� ���̺� ����
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
	// PlayerController���� HUDWidget ��������
	if (APlayerController* PlayerController = GetWorld()->GetFirstPlayerController())
	{
		if (ASpartaPlayerController* SpartaPlayerController = Cast<ASpartaPlayerController>(PlayerController))
		{
			if (UUserWidget* HUDWidget = SpartaPlayerController->GetHUDWidget())
			{
				// �ð�
				if (UTextBlock* TimeText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("TimeText"))))
				{
					// WorldTimerManager���� ���� �ð� ��������
					float RemainingTime = GetWorldTimerManager().GetTimerRemaining(WaveTimerHandle);
					// ���
					TimeText->SetText(FText::FromString(FString::Printf(TEXT("Time: %.1f"), RemainingTime)));
				}

				// ����
				if (UTextBlock* ScoreText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("ScoreText"))))
				{
					// GameInstance�� Total Score ���� -> GameInstance ��������
					if (UGameInstance* GameInstance = GetGameInstance())
					{
						USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(GameInstance);
						if (SpartaGameInstance)
						{
							// GameInstance���� Total Score �����ͼ� ���
							ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), SpartaGameInstance->TotalScore)));
						}
					}					
				}

				// ����
				if (UTextBlock* LevelText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("LevelText"))))
				{
					// ���� Index�� GameState���� ����
					LevelText->SetText(FText::FromString(FString::Printf(TEXT("Level: %d"), CurrentLevelIndex + 1)));
				}

				if (UTextBlock* WaveText = Cast<UTextBlock>(HUDWidget->GetWidgetFromName(TEXT("WaveText"))))
				{
					// ���� Index�� GameState���� ����
					WaveText->SetText(FText::FromString(FString::Printf(TEXT("Wave: %d"), CurrentWaveIndex + 1)));
				}
			}
		}
	}
}
