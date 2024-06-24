// Fill out your copyright notice in the Description page of Project Settings.


#include "OneProjectileAttackComponent.h"
#include <Kismet/KismetMathLibrary.h>
#include <PersonalTowerDefense/Component/TargetComponent/TargetComponent.h>

// Sets default values for this component's properties
UOneProjectileAttackComponent::UOneProjectileAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOneProjectileAttackComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UOneProjectileAttackComponent::ShotBehaviour()
{
	UProjectileAttackComponent::ShotBehaviour();
	const FRotator _rotator = UKismetMathLibrary::FindLookAtRotation(owner->GetActorLocation(),target->GetActorLocation());
	SpawnProjectile(_rotator);
}


// Called every frame
void UOneProjectileAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

