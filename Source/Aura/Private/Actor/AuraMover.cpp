// Copyright Sadowy Games


#include "Actor/AuraMover.h"


UAuraMover::UAuraMover() :
	MoveVelocity(0, 0, 5),
	RotationVelocity(0, 5, 0),
	MoveDistance(5.f)
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAuraMover::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetOwner()->GetActorLocation();
	if (!GetOwner()->IsRootComponentMovable())
		GetOwner()->GetRootComponent()->SetMobility(EComponentMobility::Movable);
}

void UAuraMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	Move(DeltaTime);

	Rotate(DeltaTime);
}

void UAuraMover::Move(const float DeltaTime)
{
	if (ShouldReturn())
	{
		const FVector MoveDirection = MoveVelocity.GetSafeNormal();
		StartLocation += MoveDirection * MoveDistance;
		GetOwner()->SetActorLocation(StartLocation);
		MoveVelocity *= -1;
	}
	else
	{
		FVector CurrentLocation = GetOwner()->GetActorLocation();
		CurrentLocation = CurrentLocation + MoveVelocity * DeltaTime;
		GetOwner()->SetActorLocation(CurrentLocation);
	}
}

void UAuraMover::Rotate(const float DeltaTime) const
{
	GetOwner()->AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool UAuraMover::ShouldReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}

float UAuraMover::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetOwner()->GetActorLocation());
}
