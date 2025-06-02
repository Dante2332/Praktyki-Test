// Copyright 2025 Teyon. All Rights Reserved.


#include "Vehicle.h"

// Sets default values
AVehicle::AVehicle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetupCar();
}

// Called when the game starts or when spawned
void AVehicle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVehicle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVehicle::SetupCar()
{
	CarBaseMesh = CreateDefaultSubobject<USkeletalMeshComponent>("CarBase")();
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
	FrontLeftBrakeDiscMesh->SetupAttachment(CarBaseMesh, FName("wheel_front_right_spin"));
	
	FrontRightBrakeDiscMesh = CreateDefaultSubobject<UStaticMeshComponent>("FrontRightBrakeDisc");
	FrontRightBrakeDiscMesh->SetupAttachment(CarBaseMesh);
	
	RearLeftBrakeDiscMesh = CreateDefaultSubobject<UStaticMeshComponent>("RearLeftBrakeDisc");
	RearLeftBrakeDiscMesh->SetupAttachment(CarBaseMesh);
	
	RearRightBrakeDiscMesh = CreateDefaultSubobject<UStaticMeshComponent>("RearRightBrakeDisc");
	RearRightBrakeDiscMesh->SetupAttachment(CarBaseMesh);
	
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
	SteeringWheelMesh->SetRelativeLocation(FVector(20.f, 32.f, 71.f));


	AccelerationPedalMesh = CreateDefaultSubobject<UStaticMeshComponent>("AccelerationPedal");
	AccelerationPedalMesh->SetupAttachment(CarBaseMesh);
	//Ustawić później!!!
	AccelerationPedalMesh->SetRelativeLocation(FVector(0.f, 24.f, 38.f));

	BrakePedalMesh = CreateDefaultSubobject<UStaticMeshComponent>("BrakePedal");
	BrakePedalMesh->SetupAttachment(CarBaseMesh);
	BrakePedalMesh->SetRelativeLocation(FVector(99.5f, 29.5f, 46.5f)); 
	BrakePedalMesh->SetRelativeRotation(FRotator(180.f, 0.f, 0.f));
	
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
	RearRightWheelMesh->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));

	SpoilerMesh = CreateDefaultSubobject<UStaticMeshComponent>("Spoiler");
	SpoilerMesh->SetupAttachment(CarBaseMesh, FName("spoiler_back"));
	
	LeftMirrorMesh = CreateDefaultSubobject<UStaticMeshComponent>("LeftMirror");
	LeftMirrorMesh->SetupAttachment(CarBaseMesh, FName("wing_mirror_left"));

	RightMirrorMesh = CreateDefaultSubobject<UStaticMeshComponent>("RightMirror");
	RightMirrorMesh->SetupAttachment(CarBaseMesh, FName("wing_mirror_right"));
	
	DiffuserMesh = CreateDefaultSubobject<UStaticMeshComponent>("Diffuser");
	DiffuserMesh->SetupAttachment(CarBaseMesh, FName("diffuser_back"));
	
}