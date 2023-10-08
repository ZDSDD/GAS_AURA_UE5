// Copyright Sadowy Games


#include "Character/AuraCharacterBase.h"

#include "AbilitySystemComponent.h"

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return this->AbilitySystemComponent;
}

// Sets default values
AAuraCharacterBase::AAuraCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
}

void AAuraCharacterBase::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect> GameplayEffectClass, const float Level) const
{
	check(IsValid(AbilitySystemComponent));
	check(GameplayEffectClass);

	FGameplayEffectContextHandle EffectContext = GetAbilitySystemComponent()->MakeEffectContext();
	EffectContext.AddSourceObject(this);
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(
		GameplayEffectClass, Level, EffectContext);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AAuraCharacterBase::InitializeDefaultAttributes() const
{
	InitializePrimaryAttributes();
	InitializeSecondaryAttributes();
	InitializeVitalAttributes();
}

void AAuraCharacterBase::InitializePrimaryAttributes() const
{
	ApplyEffectToSelf(this->DefaultPrimaryAttributes,1.f);
}

void AAuraCharacterBase::InitializeSecondaryAttributes() const
{
	ApplyEffectToSelf(this->DefaultSecondaryAttributes,1.f);
}

void AAuraCharacterBase::InitializeVitalAttributes() const
{
	ApplyEffectToSelf(this->DefaultVitalAttributes, 1.f);
}
