// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("A human player has joined the game."))
		auto controlledTank = GetControlledTank();
		if (controlledTank) {
			UE_LOG(LogTemp,Warning,TEXT("A human player is controlling %s"),*controlledTank->GetName())
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("A human player has no tank to control!"))

		}
}


