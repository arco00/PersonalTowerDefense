// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackComponent.h"
#include "BaseTower.h"

// Sets default values for this component's properties
UAttackComponent::UAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
	
}

void UAttackComponent::ActivateAttack(ABaseEnemy* _target)
{
	if(!_target)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerSalvo);

	}
	else 
	{
	GetWorld()->GetTimerManager().SetTimer(TimerSalvo, this, &UAttackComponent::Salvo, timeBetweenSalvo, true,timeBetweenSalvo);
	target = _target;
	}
}


// Called every frame
void UAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UAttackComponent::Salvo()
{
	GetWorld()->GetTimerManager().SetTimer(TimerShot, this, &UAttackComponent::Shot, timeBetweenShot, true, timeBetweenShot);
}

void UAttackComponent::Shot()
{
	target->AddHealth(-damage);
	actualShotFired++;
	if (actualShotFired >= salvoSize) {
		GetWorld()->GetTimerManager().ClearTimer(TimerShot);
		actualShotFired = 0;
	}
}

void UAttackComponent::Init()
{
	owner = GetOwner();
	Cast<ABaseTower>(owner)->FindComponentByClass<UTargetComponent>()->NewTarget().AddDynamic(this, &UAttackComponent::ActivateAttack);
}

