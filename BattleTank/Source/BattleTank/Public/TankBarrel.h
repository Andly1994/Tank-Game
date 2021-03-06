// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//|x|<1 speed
	void Elevate(float RelativeSpeed);
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesPerSecond = 20;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevation = 00;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevation = 40;
	
};
