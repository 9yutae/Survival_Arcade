#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "BombItem.generated.h"

UCLASS()
class SURVIVAL_ARCADE_API ABombItem : public ABaseItem
{
	GENERATED_BODY()
	
public:
	ABombItem();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bomb")
	float ExplosionRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bomb")
	float ExplosionDamage;

	UPROPERTY(EditAnywhere, Category = "Bomb")
	class UParticleSystem* ExplosionEffect;

	UPROPERTY(EditAnywhere, Category = "Bomb")
	class USoundBase* ExplosionSound;

	UPROPERTY(VisibleAnywhere, Category = "Bomb")
	class UStaticMeshComponent* BombMesh;

	UFUNCTION()
	void OnHit(
		UPrimitiveComponent* HitComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		FVector NormalImpulse,
		const FHitResult& Hit
	);

	FTimerHandle FuzeTimerHandle;

	void Explode();
};
