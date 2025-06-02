// Copyright 2025 Teyon. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vehicle.generated.h"

UCLASS()
class PRAKTYKI_API AVehicle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVehicle();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
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

	void SetupCar();

	void Accelerate(float Value);
	void Brake(float Value);
	void Turn(float Value);
};
