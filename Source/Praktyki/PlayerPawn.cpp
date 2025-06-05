// Copyright 2025 Teyon. All Rights Reserved.


#include "PlayerPawn.h"
#include "Vehicle.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FClassFinder<AVehicle> VehicleBPClass(TEXT("/Game/Blueprints/BP_Porsche"));
	VehicleToSpawn = VehicleBPClass.Class;

	//Input init
	static ConstructorHelpers::FObjectFinder<UInputMappingContext> InputContextObj(TEXT("/Game/EnhancedInput/DefaultMappingContext.DefaultMappingContext"));
	static ConstructorHelpers::FObjectFinder<UInputAction> AccelerateActionObj(TEXT("/Game/EnhancedInput/IA_Accelerate.IA_Accelerate"));
	static ConstructorHelpers::FObjectFinder<UInputAction> BrakeActionObj(TEXT("/Game/EnhancedInput/IA_Brake.IA_Brake"));
	static ConstructorHelpers::FObjectFinder<UInputAction> TurnActionObj(TEXT("/Game/EnhancedInput/IA_Turn.IA_Turn"));
	static ConstructorHelpers::FObjectFinder<UInputAction> ToggleCameraObj(TEXT("/Game/EnhancedInput/IA_ToggleCam.IA_ToggleCam"));
	
	DefaultMappingContext = InputContextObj.Object;
	AccelerateAction = AccelerateActionObj.Object;
	BrakeAction = BrakeActionObj.Object;
	TurnAction = TurnActionObj.Object;
	CameraAction = ToggleCameraObj.Object;
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

void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultMappingContext, 0);
		}
	}

	if (UEnhancedInputComponent* EnhancedInput = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInput->BindAction(AccelerateAction, ETriggerEvent::Triggered, this, &APlayerPawn::HandleAcceleration);
		EnhancedInput->BindAction(BrakeAction, ETriggerEvent::Triggered, this, &APlayerPawn::HandleBrake);
		EnhancedInput->BindAction(TurnAction, ETriggerEvent::Triggered, this, &APlayerPawn::HandleTurn);
		EnhancedInput->BindAction(CameraAction, ETriggerEvent::Started, this, &APlayerPawn::HandleCamera);
	}
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

void APlayerPawn::HandleAcceleration(const FInputActionValue& Value)
{
	ControlledVehicle->Accelerate(Value.Get<float>());
}

void APlayerPawn::HandleBrake(const FInputActionValue& Value)
{
	ControlledVehicle->Brake(Value.Get<float>());
}

void APlayerPawn::HandleTurn(const FInputActionValue& Value)
{
	ControlledVehicle->Turn(Value.Get<float>());
}

void APlayerPawn::HandleCamera()
{
	ControlledVehicle->ToggleCamera();
}