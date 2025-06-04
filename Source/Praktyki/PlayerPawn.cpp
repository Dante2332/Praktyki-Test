// Copyright 2025 Teyon. All Rights Reserved.


#include "PlayerPawn.h"
#include "Vehicle.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FClassFinder<AVehicle> VehicleBPClass(TEXT("/Game/Blueprints/BP_Porsche"));
	VehicleToSpawn = VehicleBPClass.Class;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	SpawnVehicle();
	SetCamera();
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
}

void APlayerPawn::SpawnVehicle()
{
	
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;

	FVector SpawnLocation = GetActorLocation();
	FRotator SpawnRotation = GetActorRotation();

	ControlledVehicle = GetWorld()->SpawnActor<AVehicle>(VehicleToSpawn, SpawnLocation, SpawnRotation, SpawnParameters);
}

void APlayerPawn::SetCamera()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	PlayerController->SetViewTarget(ControlledVehicle);
}