// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Movement")
	FVector VelocityVector = FVector(0, 0, 0);

	UPROPERTY(EditAnywhere, Category="Movement")
	int maxMovement = 300;

	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity;

	int YStart = 0;
	int YMax = 0;

	FVector StartLocation = FVector(0, 0, 0);

private:
	void MovePlatform(float DeltaTime);

	void RotatePlatform(float DeltaTime);

	bool ShouldReturn() const;

	float getDistanceMoved() const;
};
