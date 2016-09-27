// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const {

	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const {

	return Cast<ATank>(GetWorld()->GetFirstLocalPlayerFromController()->GetPlayerController(GetWorld())->GetPawn());
}

void ATankAIController::BeginPlay() {

	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("An AI player has joined the game."))
	auto controlledTank = GetControlledTank();
	if (controlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("An AI player is now controlling %s"), *controlledTank->GetName())
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("An AI player has no tank to control!"))

	}
	auto playerTank = GetPlayerTank();
	if (playerTank) {
		UE_LOG(LogTemp, Warning, TEXT("AI %s has found player %s"), *this->GetName(),*playerTank->GetName())
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("AI %s has not detected any players."), *this->GetName())
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation()+FVector(0.f,0.f,80.f));
}

