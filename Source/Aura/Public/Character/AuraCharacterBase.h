// Copyright Sadowy Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interaction/CombatInterface.h"
#include "AuraCharacterBase.generated.h"

class UGameplayEffect;
class UAttributeSet;
class UAbilitySystemComponent;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

	// Getters
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }

public:
	// Sets default values for this character's properties
	AAuraCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	virtual void InitAbilityActorInfo();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category= "Attributes")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	/** It needs to be initialized only after Primary Attributes!! */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category= "Attributes")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;
	
	/** It needs to be initialized only after Secondary Attributes!! */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category= "Attributes")
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;


	void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level) const;

	void InitializeDefaultAttributes() const;

	void InitializePrimaryAttributes() const;

	void InitializeSecondaryAttributes() const;
	
	void InitializeVitalAttributes() const;
};
