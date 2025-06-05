// Copyright 2025 Teyon. All Rights Reserved.


#include "Vehicle.h"

#include "Camera/CameraComponent.h"
#include "Physics/ImmediatePhysics/ImmediatePhysicsShared/ImmediatePhysicsCore.h"


AVehicle::AVehicle()
{

	PrimaryActorTick.bCanEverTick = true;
	SetupCar();
}

void AVehicle::SetupCar()
{
	CarBaseMesh = CreateDefaultSubobject<USkeletalMeshComponent>("CarBase");
	RootComponent = CarBaseMesh;
	
	MainBodyMesh = CreateDefaultSubobject<UStaticMeshComponent>("MainBody");
	MainBodyMesh->SetupAttachment(CarBaseMesh);
	
	EngineCompMesh = CreateDefaultSubobject<UStaticMeshComponent>("EngineComponents");
	EngineCompMesh->SetupAttachment(CarBaseMesh);
	
	FrontBumperMesh = CreateDefaultSubobject<UStaticMeshComponent>("FrontBumper");
	FrontBumperMesh->SetupAttachment(CarBaseMesh,FName("bumper_front"));
	
	RearBumperMesh = CreateDefaultSubobject<UStaticMeshComponent>("RearBumper");
	RearBumperMesh->SetupAttachment(CarBaseMesh, FName("bumper_rear"));
	
	NetMesh = CreateDefaultSubobject<UStaticMeshComponent>("NetMesh");
	NetMesh->SetupAttachment(CarBaseMesh);
	
	WindowsMesh = CreateDefaultSubobject<UStaticMeshComponent>("Windows");
	WindowsMesh->SetupAttachment(CarBaseMesh);
	
	LeftFenderMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeftFender");
	LeftFenderMesh->SetupAttachment(CarBaseMesh, FName("fender_left"));
	
	RightFenderMesh = CreateDefaultSubobject<UStaticMeshComponent>("RightFender");
	RightFenderMesh->SetupAttachment(CarBaseMesh, FName("fender_right"));
	
	FrontLeftBrakeDiscMesh = CreateDefaultSubobject<UStaticMeshComponent>("FrontLeftBrakeDisc");
	FrontLeftBrakeDiscMesh->SetupAttachment(CarBaseMesh, FName("wheel_front_left_spin"));
	
	FrontRightBrakeDiscMesh = CreateDefaultSubobject<UStaticMeshComponent>("FrontRightBrakeDisc");
	FrontRightBrakeDiscMesh->SetupAttachment(CarBaseMesh, FName("wheel_front_right_spin"));
	
	RearLeftBrakeDiscMesh = CreateDefaultSubobject<UStaticMeshComponent>("RearLeftBrakeDisc");
	RearLeftBrakeDiscMesh->SetupAttachment(CarBaseMesh, FName("wheel_back_left_spin"));
	
	RearRightBrakeDiscMesh = CreateDefaultSubobject<UStaticMeshComponent>("RearRightBrakeDisc");
	RearRightBrakeDiscMesh->SetupAttachment(CarBaseMesh, FName("wheel_back_right_spin"));
	
	HoodMesh = CreateDefaultSubobject<UStaticMeshComponent>("Hood");
	HoodMesh->SetupAttachment(CarBaseMesh, FName("hood_front"));
	
	BootMesh = CreateDefaultSubobject<UStaticMeshComponent>("Boot");
	BootMesh->SetupAttachment(CarBaseMesh, FName("boot_rear"));
	
	CockpitMesh = CreateDefaultSubobject<UStaticMeshComponent>("Cockpit");
	CockpitMesh->SetupAttachment(CarBaseMesh);
	
	SeatMesh = CreateDefaultSubobject<UStaticMeshComponent>("Seat");
	SeatMesh->SetupAttachment(CarBaseMesh);
	
	InteriorMesh = CreateDefaultSubobject<UStaticMeshComponent>("Interior");
	InteriorMesh->SetupAttachment(CarBaseMesh);

	SteeringWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>("SteeringWheel");
	SteeringWheelMesh->SetupAttachment(CarBaseMesh);
	SteeringWheelMesh->SetRelativeLocation(FVector(21.4f, 30.65f, 71.84f));
	SteeringWheelMesh->SetRelativeRotation(FRotator(0.f, -17.f, 0.f));

	AccelerationPedalMesh = CreateDefaultSubobject<UStaticMeshComponent>("AccelerationPedal");
	AccelerationPedalMesh->SetupAttachment(CarBaseMesh);
	AccelerationPedalMesh->SetRelativeLocation(FVector(0.f, 24.f, 38.f));

	BrakePedalMesh = CreateDefaultSubobject<UStaticMeshComponent>("BrakePedal");
	BrakePedalMesh->SetupAttachment(CarBaseMesh);
	BrakePedalMesh->SetRelativeLocation(FVector(97.56f, -29.85f, 47.44f)); 
	BrakePedalMesh->SetRelativeRotation(FRotator(180.f, -50.f, 0.f));
	
	
	LeftDoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeftDoor");
	LeftDoorMesh->SetupAttachment(CarBaseMesh, FName("door_left"));
	
	RightDoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("RightDoor");
	RightDoorMesh->SetupAttachment(CarBaseMesh, FName("door_right"));
	
	FrontLeftCaliperMesh = CreateDefaultSubobject<UStaticMeshComponent>("FrontLeftCaliper");
	FrontLeftCaliperMesh->SetupAttachment(CarBaseMesh, FName("wheel_front_left_spin"));
	
	FrontRightCaliperMesh = CreateDefaultSubobject<UStaticMeshComponent>("FrontRightCaliper");
	FrontRightCaliperMesh->SetupAttachment(CarBaseMesh, FName("wheel_front_right_spin"));
	
	RearLeftCaliperMesh = CreateDefaultSubobject<UStaticMeshComponent>("RearLeftCaliper");
	RearLeftCaliperMesh->SetupAttachment(CarBaseMesh, FName("wheel_back_left_spin"));
	
	RearRightCaliperMesh = CreateDefaultSubobject<UStaticMeshComponent>("RearRightCaliper");
	RearRightCaliperMesh->SetupAttachment(CarBaseMesh, FName("wheel_back_right_spin"));
	
	FrontLeftWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>("FrontLeftWheel");
	FrontLeftWheelMesh->SetupAttachment(CarBaseMesh, FName("wheel_front_left_spin"));
	
	FrontLeftBlurMesh = CreateDefaultSubobject<UStaticMeshComponent>("FrontLeftBlur");
	FrontLeftBlurMesh->SetupAttachment(FrontLeftWheelMesh);
	FrontLeftBlurMesh->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
	
	FrontRightWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>("FrontRightWheel");
	FrontRightWheelMesh->SetupAttachment(CarBaseMesh, FName("wheel_front_right_spin"));
	FrontRightWheelMesh->SetRelativeRotation(FRotator(0.f, 0.f, 180.f));
	
	FrontRightBlurMesh = CreateDefaultSubobject<UStaticMeshComponent>("FrontRightBlur");
	FrontRightBlurMesh->SetupAttachment(FrontRightWheelMesh);
	FrontRightBlurMesh->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
	
	RearLeftWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>("RearLeftWheel");
	RearLeftWheelMesh->SetupAttachment(CarBaseMesh, FName("wheel_back_left_spin"));
	
	RearLeftBlurMesh = CreateDefaultSubobject<UStaticMeshComponent>("RearLeftBlur");
	RearLeftBlurMesh->SetupAttachment(RearLeftWheelMesh);
	RearLeftBlurMesh->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));
	
	RearRightWheelMesh = CreateDefaultSubobject<UStaticMeshComponent>("RearRightWheel");
	RearRightWheelMesh->SetupAttachment(CarBaseMesh, FName("wheel_back_right_spin"));
	RearRightWheelMesh->SetRelativeRotation(FRotator(0.f, 0.f, 180.f));
	
	RearRightBlurMesh = CreateDefaultSubobject<UStaticMeshComponent>("RearRightBlur");
	RearRightBlurMesh->SetupAttachment(RearRightWheelMesh);
	RearRightBlurMesh->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));

	SpoilerMesh = CreateDefaultSubobject<UStaticMeshComponent>("Spoiler");
	SpoilerMesh->SetupAttachment(CarBaseMesh, FName("spoiler_back"));
	
	LeftMirrorMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeftMirror");
	LeftMirrorMesh->SetupAttachment(CarBaseMesh, FName("wing_mirror_left"));

	RightMirrorMesh = CreateDefaultSubobject<UStaticMeshComponent>("RightMirror");
	RightMirrorMesh->SetupAttachment(CarBaseMesh, FName("wing_mirror_right"));
	
	DiffuserMesh = CreateDefaultSubobject<UStaticMeshComponent>("Diffuser");
	DiffuserMesh->SetupAttachment(CarBaseMesh, FName("diffuser_back"));

	VehicleCamera = CreateDefaultSubobject<UCameraComponent>("Camera");
	VehicleCamera->SetupAttachment(CarBaseMesh, FName((CameraSockets[0])));
	
}

void AVehicle::BeginPlay()
{
	Super::BeginPlay();
	
}

void AVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateSpeed(DeltaTime);

}

void AVehicle::Accelerate(float Value)
{
	AccelerationInput = Value;
}

void AVehicle::Brake(float Value)
{
	if (Value > 0 && AccelerationInput == 0)
	{
		CurrentSpeed = FMath::FInterpConstantTo(CurrentSpeed, 0, GetWorld()->GetDeltaSeconds(), BrakeForce);
	}
}

void AVehicle::Turn(float Value)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Turn");
}

void AVehicle::ToggleCamera()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "ToggleCamera");
}

void AVehicle::UpdateSpeed(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Input: %f"), AccelerationInput));
	if (AccelerationInput > 0)
	{
		// Accelerate
		CurrentSpeed = FMath::Clamp(CurrentSpeed + AccelerationInput * AccelerationRate * DeltaTime, 0.f, MaxSpeed);
	GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Red, FString::Printf(TEXT("Current Speed: %f"), CurrentSpeed));

	}
	else
	{
		//Decelerate
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "Deceleration");
		CurrentSpeed = FMath::FInterpConstantTo(CurrentSpeed, 0, DeltaTime, DecelerationRate);
	}
	// Drive
	FVector ForwardMove = FrontRightWheelMesh->GetForwardVector() * DeltaTime;
	AddActorWorldOffset(ForwardMove * CurrentSpeed, true);
}

