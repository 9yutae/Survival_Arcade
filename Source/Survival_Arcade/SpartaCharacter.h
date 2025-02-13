#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SpartaCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UWidgetComponent;
struct FInputActionValue; 

UCLASS()
class SURVIVAL_ARCADE_API ASpartaCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASpartaCharacter();

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = "UI")
	UWidgetComponent* OverheadWidget; // HP Widget Component

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Debuff")
	void SlowDown(float DecelerationRate);
	UFUNCTION(BlueprintCallable, Category = "Debuff")
	void RestoreSpeed();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Health")
	float Health;


	virtual void BeginPlay() override;
	// virtual void Tick(float DeltaTime) override;
	// 입력 바인딩을 처리할 함수 (IA 함수 연결)
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 데미지 관련 함수 오버라이딩
	virtual float TakeDamage(
		float DamageAmount,		// 받은 데미지 양
		struct FDamageEvent const& DamageEvent,		// 데미지를 받은 유형 ( 스킬, 속성 등의 추가 정보 )
		AController* EventInstigator,		// 데미지를 누가 입혔는지 ( 지뢰를 심은 사람 )
		AActor* DamageCauser) override;		// 데미지를 일으킨 오브젝트 ( 지뢰 )



	// IA 함수를 처리할 함수 원형
	// Enhanced Input에서 액션 값은 FInputActionValue로 전달된다.
	UFUNCTION()
	void Move(const FInputActionValue& value); // 참조 (구조체는 복사 X), const : 수정 불가
	UFUNCTION()
	void ApplyCharacterRotation(float TargetYaw);
	UFUNCTION()
	void StartJump(const FInputActionValue& value); // boolean 타입은 동작을 나누는 것이 좋다
	UFUNCTION()
	void StopJump(const FInputActionValue& value);
	UFUNCTION()
	void Look(const FInputActionValue& value);
	UFUNCTION()
	void StartSprint(const FInputActionValue& value);
	UFUNCTION()
	void StopSprint(const FInputActionValue& value);
	UFUNCTION()
	void Pause(const FInputActionValue& value);

	void OnDeath();
	void UpdateOverheadHP();

private:
	// 기본 이동 속도와 달리기 속도 변수 선언
	float MaxWalkingSpeed;
	float CurrentWalkingSpeed;
	float SprintSpeedMultiplier;
	float SprintSpeed;

};
