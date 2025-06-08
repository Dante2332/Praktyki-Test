// Copyright 2025 Teyon. All Rights Reserved.


#include "Vehicle.h"

#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"


AVehicle::AVehicle()
{

	PrimaryActorTick.bCanEverTick = true;
	SetupCar();
	
	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereCollision");
	SphereComp->SetupAttachment(CarBaseMesh);
}

void AVehicle::SetupCar()
{
	CarBaseMesh = CreateDefaultSubobject<USkeletalMeshComponent>("CarBase");
	RootComponent = CarBaseMesh;
	CarBaseMesh->SetCollisionObjectType(ECC_Pawn);
	
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
	VehicleCamera->SetupAttachment(CarBaseMesh, FName((CameraSockets[CurrentCameraSocket])));

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

void AVehicle::Accelerate(float InputValue)
{
	AccelerationInput = InputValue;
}

void AVehicle::Brake(float InputValue)
{
	if (InputValue > 0 && AccelerationInput == 0)
	{
		CurrentSpeed = FMath::FInterpConstantTo(CurrentSpeed, 0, GetWorld()->GetDeltaSeconds(), BrakeForce);
	}
}

void AVehicle::Turn(float InputValue)
{
	
	TurnWheels(InputValue);
	UpdateCarRotation(InputValue);
}


void AVehicle::ToggleCamera()
{
	if (CurrentCameraSocket < CameraSockets.Num() - 1)
	{
		CurrentCameraSocket++;
	} else
	{
		CurrentCameraSocket = 0;
	}
		
	VehicleCamera->AttachToComponent(CarBaseMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, CameraSockets[CurrentCameraSocket]);
}

void AVehicle::ShiftUp()
{
	if (bIsOnReverse && CurrentGear == 0 && CurrentSpeed > 100.f) return;
	
	CurrentGear = FMath::Clamp(CurrentGear + 1, -1, 1);

	if (CurrentGear == 1)
	{
		bIsOnReverse = false;
	}
}

void AVehicle::ShiftDown()
{
	if (CurrentGear == 0 && CurrentSpeed > 100.f) return;
	
	CurrentGear = FMath::Clamp(CurrentGear - 1, -1, 1);
	if (CurrentGear == -1)
	{
		bIsOnReverse = true;
	}
}


void AVehicle::UpdateSpeed(float DeltaTime)
{
	if (AccelerationInput > 0 && CurrentGear == 1)
	{
		// Accelerate
		CurrentSpeed = FMath::Clamp(CurrentSpeed + AccelerationInput * AccelerationRate * DeltaTime, 0.f, MaxSpeed);

	}
	else if (AccelerationInput > 0 && CurrentGear == -1)
	{
		CurrentSpeed = FMath::Clamp(CurrentSpeed + AccelerationInput * AccelerationRate * DeltaTime, 0.f, MaxReverseSpeed);	
	}
	{
		//Decelerate
		CurrentSpeed = FMath::FInterpConstantTo(CurrentSpeed, 0, DeltaTime, DecelerationRate);
	}
	
	if (!bIsOnReverse)
	{
		// Drive Forward
		FVector ForwardMove = GetActorForwardVector() * DeltaTime * CurrentSpeed;;
		AddActorWorldOffset(ForwardMove, true);
	}
	else
	{
		// Drive Backwards
		FVector BackwardMove = GetActorForwardVector() * -1 * DeltaTime * CurrentSpeed;
		AddActorWorldOffset(BackwardMove, true);
	}
}

void AVehicle::UpdateCarRotation(float InputValue)
{
	if (CurrentSpeed > 0)
	{
		AddActorLocalRotation(FRotator(0.f, InputValue * CurrentMaxSteeringAngle * GetWorld()->GetDeltaSeconds(), 0.f));
	}
}


void AVehicle::TurnWheels(float InputValue)
{
	float SpeedFactor = FMath::Clamp(CurrentSpeed / MaxSteeringSpeed, 0.f, 1.f);
	CurrentMaxSteeringAngle = FMath::Lerp(MaxSteeringAngle, MinSteeringAngle, SpeedFactor);
	
	AxlesDistance = FVector(FrontRightWheelMesh->GetComponentLocation() - RearRightWheelMesh->GetComponentLocation()).Size();
	AxleLength = FVector(FrontRightWheelMesh->GetComponentLocation() - FrontLeftWheelMesh->GetComponentLocation()).Size();
	float Angle = FMath::Clamp(InputValue, -1.f, 1.f) * CurrentMaxSteeringAngle;;
	float AngleRad = FMath::DegreesToRadians(Angle);
    Angle = 0.f;
	float TurnRadius = AxlesDistance/ FMath::Tan(AngleRad);
	float InnerAngle = FMath::RadiansToDegrees(FMath::Atan(AxlesDistance/ (TurnRadius - (AxleLength / 2))));
	float OuterAngle = FMath::RadiansToDegrees(FMath::Atan(AxlesDistance / (TurnRadius + (AxleLength / 2))));

	

	if (InputValue > 0) 
	{
		CurrentLeftAngle = FMath::FInterpConstantTo(CurrentLeftAngle, InnerAngle, GetWorld()->GetDeltaSeconds(), CurrentSteeringSpeed);
		CurrentRightAngle = FMath::FInterpConstantTo(CurrentRightAngle, OuterAngle, GetWorld()->GetDeltaSeconds(), CurrentSteeringSpeed);
		FrontLeftWheelMesh->SetRelativeRotation(FRotator(0.f, CurrentLeftAngle, 0.f));
		FrontRightWheelMesh->SetRelativeRotation(FRotator(0.f, CurrentRightAngle, 180.f));
	}
	else if (InputValue < 0)
	{
		CurrentLeftAngle = FMath::FInterpConstantTo(CurrentLeftAngle, OuterAngle, GetWorld()->GetDeltaSeconds(), CurrentSteeringSpeed);
		CurrentRightAngle = FMath::FInterpConstantTo(CurrentRightAngle, InnerAngle, GetWorld()->GetDeltaSeconds(), CurrentSteeringSpeed);
		FrontLeftWheelMesh->SetRelativeRotation(FRotator(0.f, CurrentLeftAngle, 0.f));
		FrontRightWheelMesh->SetRelativeRotation(FRotator(0.f, CurrentRightAngle, 180.f));
	}
	else
	{
		CurrentLeftAngle = FMath::FInterpConstantTo(CurrentLeftAngle, 0, GetWorld()->GetDeltaSeconds(), CurrentSteeringSpeed);
		CurrentRightAngle = FMath::FInterpConstantTo(CurrentRightAngle, 0, GetWorld()->GetDeltaSeconds(), CurrentSteeringSpeed);
		FrontLeftWheelMesh->SetRelativeRotation(FRotator(0.f, CurrentLeftAngle, 0.f));
		FrontRightWheelMesh->SetRelativeRotation(FRotator(0.f, CurrentRightAngle, 180.f));
	}

}