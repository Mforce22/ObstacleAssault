// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	YStart = GetActorLocation().Y;

	YMax = YStart + maxMovement;	

	StartLocation = GetActorLocation();

	UE_LOG(LogTemp, Display, TEXT("Configured move distance: %f"), maxMovement);
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();

	CurrentLocation+= VelocityVector * DeltaTime;

	SetActorLocation(CurrentLocation);

	

	if(ShouldReturn())
	{
		
		FVector MoveDirection = VelocityVector.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * maxMovement;
		SetActorLocation(StartLocation);
		VelocityVector *= -1;
	}
}

bool AMovingPlatform::ShouldReturn() const
{
	float distanceMoved = getDistanceMoved();
	return distanceMoved > maxMovement;
}

float AMovingPlatform::getDistanceMoved() const
{
	return FVector::Dist(StartLocation , GetActorLocation());
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

