#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "SpartaGameState.generated.h"

UCLASS()
class SURVIVAL_ARCADE_API ASpartaGameState : public AGameState
{
	GENERATED_BODY()

public:
	ASpartaGameState();

	// 게임 시작 시 초기화
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
	int32 Score;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 SpawnedCoinCount;  // 스폰된 코인 개수
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 CollectedCoinCount;	// 캐릭터가 획득한 아이템 개수
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	int32 CurrentLevelIndex;	// 현재 레벨
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 MaxLevel;			// 최대 레벨
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wave")
	float WaveDuration;		// Wave 제한 시간
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 CurrentWaveIndex;	// 현재 Wave
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 MaxWave;			// 최대 레벨

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	TArray<FName> LevelMapNames;

	FTimerHandle WaveTimerHandle;  // 웨이브 타이머
	FTimerHandle HUDUpdateTimerHandle; // HUD Widget Update 타이머

	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const;

	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);
	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnGameOver();	// 게임 종료

	void StartLevel();	// 레벨을 시작
	void StartWave();
	void OnWaveTimeUp();	// 제한 시간 초과
	void OnCoinCollected();	// 코인 획득
	void EndLevel();	// 레벨 종료
	void EndWave();
	void UpdateHUD();	// HUD Update
};
