// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
private:

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333f;
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float) override;
	
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector &HitLocation) const;
	FVector GetLookVectorHitLocation();
	UPROPERTY(EditAnywhere)
		float LineTraceLength = 1000000;
};
