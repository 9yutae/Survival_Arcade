#include "SpartaGameMode.h"
#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"
#include "SpartaGameState.h"

ASpartaGameMode::ASpartaGameMode()
{
	// DefaultPawnClass ����
	DefaultPawnClass = ASpartaCharacter::StaticClass(); // StaticClass = ��ü�� �������� �ʰ� UCLASS �� ��ȯ (���� ����)

	// PlayerController Class  ����
	PlayerControllerClass = ASpartaPlayerController::StaticClass();

	// GameStateClass ����
	GameStateClass = ASpartaGameState::StaticClass();
}
