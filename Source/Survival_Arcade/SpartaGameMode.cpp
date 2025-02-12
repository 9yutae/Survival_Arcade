#include "SpartaGameMode.h"
#include "SpartaCharacter.h"
#include "SpartaPlayerController.h"
#include "SpartaGameState.h"

ASpartaGameMode::ASpartaGameMode()
{
	// DefaultPawnClass 설정
	DefaultPawnClass = ASpartaCharacter::StaticClass(); // StaticClass = 객체를 생성하지 않고 UCLASS 형 반환 (선언 가능)

	// PlayerController Class  설정
	PlayerControllerClass = ASpartaPlayerController::StaticClass();

	// GameStateClass 설정
	GameStateClass = ASpartaGameState::StaticClass();
}
