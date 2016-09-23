// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"))
		auto controlledTank = GetControlledTank();
		if (controlledTank) {
			UE_LOG(LogTemp,Warning,TEXT("Controlling %s"),*controlledTank->GetName())
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("No Tank Controlled"))

		}
}


