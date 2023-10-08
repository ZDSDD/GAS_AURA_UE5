// Copyright Sadowy Games

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class AAuraPlayerState;
class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter();
	virtual void InitAbilityActorInfo() override;

private:
	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
	UPROPERTY(EditAnywhere, Category="Camera")
	TObjectPtr<UCameraComponent> FollowCamera;

public:
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	virtual int32 GetCharacterLevel() override;

};
