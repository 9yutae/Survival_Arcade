#include "SpartaGameInstance.h"

USpartaGameInstance::USpartaGameInstance()
{
	// 멤버 변수 초기화
	TotalScore = 0;
	CurrentLevelIndex = 0;
}

void USpartaGameInstance::AddToScore(int32 Amount)
{
	TotalScore += Amount;
	UE_LOG(LogTemp, Warning, TEXT("Total Score Updated: %d"), TotalScore);
}
