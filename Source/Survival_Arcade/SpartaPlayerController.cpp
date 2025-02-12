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
    
    // Main Level일 경우, Main Menu 출력
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

// 게임 HUD 출력
void ASpartaPlayerController::ShowGameHUD()
{
    ResetMenu();

    if (HUDWidgetClass)
    {
        HUDWidgetInstance = CreateWidget<UUserWidget>(this, HUDWidgetClass);
        if (HUDWidgetInstance)
        {
            HUDWidgetInstance->AddToViewport();

            // Cursor 사라지게, InputMode는 게임만!
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

// 메인 메뉴 창 띄우기
void ASpartaPlayerController::ShowMainMenu()
{
    ResetMenu();

    // Main Menu Widget 생성
    if (MainMenuWidgetClass)
    {
        MainMenuWidgetInstance = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);
        if (MainMenuWidgetInstance)
        {
            MainMenuWidgetInstance->AddToViewport();

            // 메뉴 창을 띄운 채, 마우스를 움직였을 때 시점 고정
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

        // Total Score 출력할 위젯 가져오기
        if (UTextBlock* TotalScoreText = Cast<UTextBlock>(PauseMenuWidgetInstance->GetWidgetFromName("ScoreText")))
        {
            // GameInstance에서 총점 가져오기
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

    // Game Over Menu Widget 생성
    if (GameOverMenuWidgetClass)
    {
        GameOverMenuWidgetInstance = CreateWidget<UUserWidget>(this, GameOverMenuWidgetClass);
        if (GameOverMenuWidgetInstance)
        {
            GameOverMenuWidgetInstance->AddToViewport();

            // 메뉴 창을 띄운 채, 마우스를 움직였을 때 시점 고정
            bShowMouseCursor = true;
            SetInputMode(FInputModeUIOnly());
        }

        // 애니메이션 적용
        UFunction* PlayAnimFunc = GameOverMenuWidgetInstance->FindFunction(FName("PlayGameOverAnim"));
        if (PlayAnimFunc)
        {
            GameOverMenuWidgetInstance->ProcessEvent(PlayAnimFunc, nullptr); // 매개 변수가 없는 함수의 경우 두 번째 인자가 nullptr
        }

        // Total Score 출력할 위젯 가져오기
        if (UTextBlock* TotalScoreText = Cast<UTextBlock>(GameOverMenuWidgetInstance->GetWidgetFromName("TotalScoreText")))
        {
            // GameInstance에서 총점 가져오기
            if (USpartaGameInstance* SpartaGameInstance = Cast<USpartaGameInstance>(UGameplayStatics::GetGameInstance(this)))
            {
                TotalScoreText->SetText(FText::FromString(
                    FString::Printf(TEXT("Total Score: %d"), SpartaGameInstance->TotalScore)
                ));
            }
        }
    }
}

// 전체 게임 재시작
void ASpartaPlayerController::StartGame()
{
    // Game Instance 초기화
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

// 게임 종료
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
    // 기존 메뉴 제거
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
