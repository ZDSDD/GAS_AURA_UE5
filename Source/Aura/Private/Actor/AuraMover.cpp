// Copyright Sadowy Games


#include "Actor/AuraMover.h"


UAuraMover::UAuraMover()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UAuraMover::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAuraMover::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

