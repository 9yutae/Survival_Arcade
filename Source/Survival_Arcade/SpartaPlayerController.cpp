#include "SpartaPlayerController.h"
#include "SpartaGameState.h"
#include "SpartaGameInstance.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"

ASpartaPlayerController::ASpartaPlayerController()
    : InputMappingContext(nullptr),
    MoveAction(nullptr),
    JumpAction(nullptr),
    LookAction(nullptr),
    SprintAction(nullptr),
    PauseAction(nullptr),
    HUDWidgetClass(nullptr),
    HUDWidgetInstance(nullptr),
    MainMenuWidgetClass(nullptr),
    MainMenuWidgetInstance(nullptr),
    PauseMenuWidgetClass(nullptr),
    PauseMenuWidgetInstance(nullptr),
    GameOverMenuWidgetClass(nullptr),
    GameOverMenuWidgetInstance(nullptr)
{
}

void ASpartaPlayerController::BeginPlay()
{
	Super::BeginPlay();
    
	if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
	{
        if (UEnhancedInputLocalPlayerSubsystem* SubSystem =
            LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (InputMappingContext)
            {
                SubSystem->AddMappingContext(InputMappingContext, 0);
            }
        }
	}
    
    // Main Level�� ���, Main Menu ���
    FString CurrentMapName = GetWorld()->GetMapName();
    if (CurrentMapName.Contains("MenuLevel"))
    {
        ShowMainMenu();
    }
}

UUserWidget* ASpartaPlayerController::GetHUDWidget() const
{
    return HUDWidgetInstance;
}

// ���� HUD ���
void ASpartaPlayerController::ShowGameHUD()
{
    ResetMenu();

    if (HUDWidgetClass)
    {
        HUDWidgetInstance = CreateWidget<UUserWidget>(this, HUDWidgetClass);
        if (HUDWidgetInstance)
        {
            HUDWidgetInstance->AddToViewport();

            // Cursor �������, InputMode�� ���Ӹ�!
            bShowMouseCursor = false;
            SetInputMode(FInputModeGameOnly());

            ASpartaGameState* SpartaGameState = GetWorld() ? GetWorld()->GetGameState<ASpartaGameState>() : nullptr;
            if (SpartaGameState)
            {
                SpartaGameState->UpdateHUD();
            }
        }
    }
}

// ���� �޴� â ����
void ASpartaPlayerController::ShowMainMenu()
{
    ResetMenu();

    // Main Menu Widget ����
    if (MainMenuWidgetClass)
    {
        MainMenuWidgetInstance = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
        if (MainMenuWidgetInstance)
        {
            MainMenuWidgetInstance->AddToViewport();

            // �޴� â�� ��� ä, ���콺�� �������� �� ���� ����
            bShowMouseCursor = true;
            SetInputMode(FInputModeUIOnly());
        }
    }
}

void ASpartaPlayerController::TogglePauseMenu()
{
    if (IsPaused())
    {
        SetPause(false);
        if (PauseMenuWidgetInstance)
        {
            PauseMenuWidgetInstance->RemoveFromParent();
            PauseMenuWidgetInstance = nullptr;
        }
        ShowGameHUD();
    }
    else
    {
        SetPause(true);
        ShowPauseMenu();
    }
}

void ASpartaPlayerController::ShowPauseMenu()
{
    ResetMenu();

    if (PauseMenuWidgetClass)
    {
        PauseMenuWidgetInstance = CreateWidget<UUserWidget>(this, PauseMenuWidgetClass);
        if (PauseMenuWidgetInstance)
        {
            PauseMenuWidgetInstance->AddToViewport();
            bShowMouseCursor = true;
            SetInputMode(FInputModeUIOnly());
        }

        // Total Score ����� ���� ��������
        if (UTextBlock* TotalScoreText = Cast<UTextBlock>(PauseMenuWidgetInstance->GetWidgetFromName("ScoreText")))
        {
            // GameInstance���� ���� ��������
            if (USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(UGameplayStatics::GetGameInstance(this)))
            {
                TotalScoreText->SetText(FText::FromString(
                    FString::Printf(TEXT("Score: %d"), SpartaGameInstance->TotalScore)
                ));
            }
        }
    }
}

void ASpartaPlayerController::ShowGameOverMenu()
{
    ResetMenu();

    // Game Over Menu Widget ����
    if (GameOverMenuWidgetClass)
    {
        GameOverMenuWidgetInstance = CreateWidget<UUserWidget>(this, GameOverMenuWidgetClass);
        if (GameOverMenuWidgetInstance)
        {
            GameOverMenuWidgetInstance->AddToViewport();

            // �޴� â�� ��� ä, ���콺�� �������� �� ���� ����
            bShowMouseCursor = true;
            SetInputMode(FInputModeUIOnly());
        }

        // �ִϸ��̼� ����
        UFunction* PlayAnimFunc = GameOverMenuWidgetInstance->FindFunction(FName("PlayGameOverAnim"));
        if (PlayAnimFunc)
        {
            GameOverMenuWidgetInstance->ProcessEvent(PlayAnimFunc, nullptr); // �Ű� ������ ���� �Լ��� ��� �� ��° ���ڰ� nullptr
        }

        // Total Score ����� ���� ��������
        if (UTextBlock* TotalScoreText = Cast<UTextBlock>(GameOverMenuWidgetInstance->GetWidgetFromName("TotalScoreText")))
        {
            // GameInstance���� ���� ��������
            if (USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(UGameplayStatics::GetGameInstance(this)))
            {
                TotalScoreText->SetText(FText::FromString(
                    FString::Printf(TEXT("Total Score: %d"), SpartaGameInstance->TotalScore)
                ));
            }
        }
    }
}

// ��ü ���� �����
void ASpartaPlayerController::StartGame()
{
    // Game Instance �ʱ�ȭ
    if (USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(UGameplayStatics::GetGameInstance(this)))
    {
        SpartaGameInstance->CurrentLevelIndex = 0;
        SpartaGameInstance->TotalScore = 0;
    }

    UGameplayStatics::OpenLevel(GetWorld(), FName("BasicLevel"));
    SetPause(false);
}

void ASpartaPlayerController::ContinueGame()
{

}

// ���� ����
void ASpartaPlayerController::EndGame()
{
    if (UWorld* World = GetWorld())
    {
        if (APlayerController* PlayerController = World->GetFirstPlayerController())
        {
            UKismetSystemLibrary::QuitGame(
                World,
                PlayerController,
                EQuitPreference::Quit,
                false
            );
        }
    }
}

void ASpartaPlayerController::ResetMenu()
{
    // ���� �޴� ����
    if (HUDWidgetInstance)
    {
        HUDWidgetInstance->RemoveFromParent();
        HUDWidgetInstance = nullptr;
    }

    if (MainMenuWidgetInstance)
    {
        MainMenuWidgetInstance->RemoveFromParent();
        MainMenuWidgetInstance = nullptr;
    }

    if (PauseMenuWidgetInstance)
    {
        PauseMenuWidgetInstance->RemoveFromParent();
        PauseMenuWidgetInstance = nullptr;
    }

    if (GameOverMenuWidgetInstance)
    {
        GameOverMenuWidgetInstance->RemoveFromParent();
        GameOverMenuWidgetInstance = nullptr;
    }
}
