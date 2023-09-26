// Copyright Sadowy Games


#include "Player/AuraPlayerState.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return this->AbilitySystemComponent;
}

AAuraPlayerState::AAuraPlayerState()
{
	NetUpdateFrequency = 100.f;

	this->AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	this->AbilitySystemComponent->SetIsReplicated(true);

	this->AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}
