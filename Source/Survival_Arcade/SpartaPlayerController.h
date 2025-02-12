#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpartaPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class SURVIVAL_ARCADE_API ASpartaPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ASpartaPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SprintAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* PauseAction;

	// HUD Widget Class
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	TSubclassOf<UUserWidget> HUDWidgetClass;
	// HUD Widget Instance
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "HUD")
	UUserWidget* HUDWidgetInstance;
	// Menu Widget Class
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;
	// Menu Widget Instance
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Menu")
	UUserWidget* MainMenuWidgetInstance;
	// Menu Widget Class
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
	TSubclassOf<UUserWidget> PauseMenuWidgetClass;
	// Menu Widget Instance
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Menu")
	UUserWidget* PauseMenuWidgetInstance;
	// Menu Widget Class
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Menu")
	TSubclassOf<UUserWidget> GameOverMenuWidgetClass;
	// Menu Widget Instance
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Menu")
	UUserWidget* GameOverMenuWidgetInstance;

	UFUNCTION(BlueprintPure, Category = "HUD")
	UUserWidget* GetHUDWidget() const;

	UFUNCTION(BlueprintCallable, Category = "HUD")
	void ShowGameHUD();		// HUD â �ҷ�����
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowMainMenu();	// Main Menu �ҷ�����
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void TogglePauseMenu();
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowPauseMenu();	// Pause Menu �ҷ�����
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ShowGameOverMenu();	// GameOver Menu �ҷ�����
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void StartGame();		// Game Start (����� ����)
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void ContinueGame();		// Game ����
	UFUNCTION(BlueprintCallable, Category = "Menu")
	void EndGame();		// Game ����

	void ResetMenu();

protected:
	virtual void BeginPlay() override;

};
