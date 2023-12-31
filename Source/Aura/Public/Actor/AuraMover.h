﻿// Copyright Sadowy Games

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AuraMover.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AURA_API UAuraMover : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UAuraMover();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere, Category = "Mover")
	FVector MoveVelocity;

	UPROPERTY(EditAnywhere, Category = "Mover")
	FRotator RotationVelocity;

	UPROPERTY(EditAnywhere, Category = "Mover")
	float MoveDistance;

	FVector StartLocation{};

private:
	void Move(const float DeltaTime);

	FORCEINLINE void Rotate(const float DeltaTime) const;

	FORCEINLINE bool ShouldReturn() const;

	FORCEINLINE float GetDistanceMoved() const;
};
