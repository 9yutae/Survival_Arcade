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
	// �Է� ���ε��� ó���� �Լ� (IA �Լ� ����)
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// ������ ���� �Լ� �������̵�
	virtual float TakeDamage(
		float DamageAmount,		// ���� ������ ��
		struct FDamageEvent const& DamageEvent,		// �������� ���� ���� ( ��ų, �Ӽ� ���� �߰� ���� )
		AController* EventInstigator,		// �������� ���� �������� ( ���ڸ� ���� ��� )
		AActor* DamageCauser) override;		// �������� ����Ų ������Ʈ ( ���� )



	// IA �Լ��� ó���� �Լ� ����
	// Enhanced Input���� �׼� ���� FInputActionValue�� ���޵ȴ�.
	UFUNCTION()
	void Move(const FInputActionValue& value); // ���� (����ü�� ���� X), const : ���� �Ұ�
	UFUNCTION()
	void ApplyCharacterRotation(float TargetYaw);
	UFUNCTION()
	void StartJump(const FInputActionValue& value); // boolean Ÿ���� ������ ������ ���� ����
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
	// �⺻ �̵� �ӵ��� �޸��� �ӵ� ���� ����
	float MaxWalkingSpeed;
	float CurrentWalkingSpeed;
	float SprintSpeedMultiplier;
	float SprintSpeed;

};
