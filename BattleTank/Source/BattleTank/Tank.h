// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()
public:
	void AimAt(FVector HitLocation);
	UFUNCTION(BlueprintCallable,Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet, UTankTurret * TurretToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();
private:
	UPROPERTY(EditDefaultsOnly,Category = Firing)
	float LaunchSpeed = 8000.f;
	UPROPERTY(EditDefaultsOnly,Category = Firing)
	float ReloadTimeInSeconds = 3;
	double LastFireTime = 0;
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBluePrint;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UTankBarrel * Barrel;
protected:

	UTankAimingComponent *TankAimingComponent = nullptr;


	
	
};
