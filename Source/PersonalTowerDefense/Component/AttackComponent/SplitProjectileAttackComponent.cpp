// Fill out your copyright notice in the Description page of Project Settings.


#include "SplitProjectileAttackComponent.h"
#include <Kismet/KismetMathLibrary.h>
#include <PersonalTowerDefense/Component/TargetComponent/TargetComponent.h>

// Sets default values for this component's properties
USplitProjectileAttackComponent::USplitProjectileAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USplitProjectileAttackComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USplitProjectileAttackComponent::ShotBehaviour()
{
	UProjectileAttackComponent::ShotBehaviour();
	const float _baseAngle = shotAngle / (projectileNumber - 1);
	for (int i = 0; i < projectileNumber; i++)
	{
		const FRotator _baseRotator = UKismetMathLibrary::FindLookAtRotation(owner->GetActorLocation(), target->GetActorLocation());
		const FRotator _rotator = _baseRotator - FRotator(0, shotAngle / 2, 0) + FRotator(0, i * _baseAngle, 0);
		SpawnProjectile(_rotator);
	}

}




// Called every frame
void USplitProjectileAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

