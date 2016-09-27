// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.f, 1.f);
	auto ElevationSpeed = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationSpeed;
	RawNewElevation = FMath::Clamp(RawNewElevation, MinElevation, MaxElevation);
	SetRelativeRotation(FRotator(RawNewElevation, 0.f, 0.f));
}



