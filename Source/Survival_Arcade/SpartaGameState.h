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

	// ���� ���� �� �ʱ�ȭ
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Score")
	int32 Score;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 SpawnedCoinCount;  // ������ ���� ����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Coin")
	int32 CollectedCoinCount;	// ĳ���Ͱ� ȹ���� ������ ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	int32 CurrentLevelIndex;	// ���� ����
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Level")
	int32 MaxLevel;			// �ִ� ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wave")
	float WaveDuration;		// Wave ���� �ð�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 CurrentWaveIndex;	// ���� Wave
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Wave")
	int32 MaxWave;			// �ִ� ����

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Level")
	TArray<FName> LevelMapNames;

	FTimerHandle WaveTimerHandle;  // ���̺� Ÿ�̸�
	FTimerHandle HUDUpdateTimerHandle; // HUD Widget Update Ÿ�̸�

	UFUNCTION(BlueprintPure, Category = "Score")
	int32 GetScore() const;

	UFUNCTION(BlueprintCallable, Category = "Score")
	void AddScore(int32 Amount);
	UFUNCTION(BlueprintCallable, Category = "Level")
	void OnGameOver();	// ���� ����

	void StartLevel();	// ������ ����
	void StartWave();
	void OnWaveTimeUp();	// ���� �ð� �ʰ�
	void OnCoinCollected();	// ���� ȹ��
	void EndLevel();	// ���� ����
	void EndWave();
	void UpdateHUD();	// HUD Update
};
