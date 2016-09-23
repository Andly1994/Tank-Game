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

//Tick
	//Super
	//AimTowardsCrosshair

void ATankPlayerController::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
	//UE_LOG(LogTemp,Warning,TEXT("Ticking"))
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		FHitResult HitResult;
		auto LineStart = PlayerCameraManager->GetCameraLocation();
		auto LineEnd = LineStart + LineTraceLength * HitLocation;
		GetWorld()->LineTraceSingleByChannel(HitResult, LineStart, LineEnd, ECollisionChannel::ECC_Visibility);
			HitLocation = HitResult.Location;
			GetControlledTank()->AimAt(HitLocation);
		
		
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	//DrawDebugLine(GetWorld(),this->PlayerCameraManager->GetCameraLocation(), this->PlayerCameraManager->GetCameraLocation()+this->GetViewportSize/6*)
	FVector WorldLocation;
	DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation,HitLocation);
	return true;
}




