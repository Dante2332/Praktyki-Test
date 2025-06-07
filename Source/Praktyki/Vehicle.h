// Copyright 2025 Teyon. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vehicle.generated.h"

class USphereComponent;
class UCameraComponent;

UCLASS()
class PRAKTYKI_API AVehicle : public AActor
{
	GENERATED_BODY()
	
public:	
	AVehicle();

	virtual void Tick(float DeltaTime) override;

	void Accelerate(float InputValue);
	void Brake(float InputValue);
	void Turn(float InputValue);
	void ToggleCamera();
	
protected:
	virtual void BeginPlay() override;



private:
	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComp;
	// Car build
	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* CarBaseMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* MainBodyMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* EngineCompMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* FrontBumperMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RearBumperMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* NetMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* WindowsMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* LeftFenderMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RightFenderMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* FrontLeftBrakeDiscMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* FrontRightBrakeDiscMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RearLeftBrakeDiscMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RearRightBrakeDiscMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* HoodMesh;
		
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BootMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CockpitMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SeatMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* InteriorMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SteeringWheelMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* AccelerationPedalMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BrakePedalMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* LeftDoorMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RightDoorMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* FrontLeftCaliperMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* FrontRightCaliperMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RearLeftCaliperMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RearRightCaliperMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* FrontLeftWheelMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* FrontRightWheelMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RearLeftWheelMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RearRightWheelMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* FrontLeftBlurMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* FrontRightBlurMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RearLeftBlurMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RearRightBlurMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* SpoilerMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* LeftMirrorMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RightMirrorMesh;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* DiffuserMesh;

	//Cameras
	UPROPERTY(EditAnywhere)
	UCameraComponent* VehicleCamera;

	UPROPERTY(EditAnywhere)
	TArray<FName> CameraSockets = {
		"BehindCarGameplayCameraFar","BehindCarGameplayCameraNear", "CarInteriorGameplayCamera", "HoodOnGameplayCamera", "HoodGameplayCamera"
	};
	int CurrentCameraSocket = 0;
	void SetupCar();
private:
	// Car stats

	float AccelerationInput;
	float AccelerationRate = 1000.f;
	float CurrentSpeed = 0.0f;
	float MaxSpeed = 4000.0f;
	
	float DecelerationRate = 300.f;
	float BrakeForce = 800.f;
	
	float AxlesDistance;
	float AxleLength;
	float MaxSteeringAngle = 35.f;
	float SteeringSpeed = 100.f;
	float CurrentLeftAngle;
	float CurrentRightAngle;

	void UpdateSpeed(float DeltaTime);
	void UpdateCarRotation(float InputValue);
	void TurnWheels(float InputValue);

};
