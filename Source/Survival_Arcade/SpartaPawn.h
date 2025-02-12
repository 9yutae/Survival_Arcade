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

	// ��Ʈ ������Ʈ ������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpartaPawn|Components");
	USceneComponent* SceneRoot;

	// ���̷�Ż �޽� ������Ʈ ������
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "SpartaPawn|Components");
	USkeletalMeshComponent* SkeletalMeshComp;
	
	// ������ �� ������Ʈ ������
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;

	// ī�޶� ������Ʈ ������
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;

	// �̵� �ӵ�
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "MovingPlatform|Movement");
	float Speed;

	// Ÿ�̸�
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MovingPlatform|Timer");
	float Timer;

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
