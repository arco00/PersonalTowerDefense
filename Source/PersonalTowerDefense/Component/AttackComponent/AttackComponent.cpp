// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackComponent.h"
#include "PersonalTowerDefense/Spawned/Tower/BaseTower.h"
#include "PersonalTowerDefense/Spawned/Enemy/BaseEnemy.h"

// Sets default values for this component's properties
UAttackComponent::UAttackComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UAttackComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();
}

void UAttackComponent::ActivateAttack(ABaseEnemy* _target)
{
	if( !(IsValid(_target )) || _target==nullptr)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerSalvo);
	}
	else 
	{
	GetWorld()->GetTimerManager().SetTimer(TimerSalvo, this, &UAttackComponent::Salvo, timeBetweenSalvo, true,timeBetweenSalvo-timeFromLastSalvo);
	target = _target;
	}
}


// Called every frame
void UAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	timeFromLastSalvo += GetWorld()->DeltaTimeSeconds;
	timeFromLastSalvo = timeFromLastSalvo >= timeBetweenSalvo ? timeBetweenSalvo : timeFromLastSalvo;

}

void UAttackComponent::Salvo()
{
	GetWorld()->GetTimerManager().SetTimer(TimerShot, this, &UAttackComponent::Shot, timeBetweenShot, true, timeBetweenShot);
	timeFromLastSalvo = 0;
}

void UAttackComponent::Shot()
{
	onShot.Broadcast();
	if (!IsValid(target))return;
	if ( target==nullptr)return;
	UE_LOG(LogTemp, Warning, TEXT("shot"));
	ShotBehaviour();
	actualShotFired++;

	if (actualShotFired >= salvoSize) 
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerShot);
		actualShotFired = 0;
	}
}

void UAttackComponent::Init()
{
	owner = GetOwner();
	Cast<ABaseTower>(owner)->FindComponentByClass<UTargetComponent>()->NewTarget().AddDynamic(this, &UAttackComponent::ActivateAttack);
	
}

void UAttackComponent::ShotBehaviour()
{
	// for children
}
