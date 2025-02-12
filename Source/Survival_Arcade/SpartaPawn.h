#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SpartaPawn.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class SURVIVAL_ARCADE_API ASpartaPawn : public APawn
{
	GENERATED_BODY()

public:
	ASpartaPawn();

	// 루트 컴포넌트 포인터
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpartaPawn|Components");
	USceneComponent* SceneRoot;

	// 스켈레탈 메시 컴포넌트 포인터
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpartaPawn|Components");
	USkeletalMeshComponent* SkeletalMeshComp;
	
	// 스프링 암 컴포넌트 포인터
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;

	// 카메라 컴포넌트 포인터
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;

	// 이동 속도
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MovingPlatform|Movement");
	float Speed;

	// 타이머
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingPlatform|Timer");
	float Timer;

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
