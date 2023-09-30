// Copyright Sadowy Games


#include "Actor/AuraEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "Kismet/GameplayStatics.h"

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, const TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetAbilitySystemComponent =
		UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	if (!TargetAbilitySystemComponent) return;

	check(GameplayEffectClass);
	
	FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();
	
	EffectContextHandle.AddSourceObject(this);
	
	const FGameplayEffectSpecHandle EffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(
		GameplayEffectClass, 1.f, EffectContextHandle);
	
	TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}

void AAuraEffectActor::OnOverlap(AActor* TargetActor)
{
	
}

void AAuraEffectActor::OnEndOverlap(AActor* TargetActor)
{
}
