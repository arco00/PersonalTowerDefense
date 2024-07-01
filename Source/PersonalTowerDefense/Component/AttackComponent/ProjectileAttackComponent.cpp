// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileAttackComponent.h"
#include <Kismet/KismetMathLibrary.h>
#include <PersonalTowerDefense/Component/TargetComponent/TargetComponent.h>

// Sets default values for this component's properties
UProjectileAttackComponent::UProjectileAttackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UProjectileAttackComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

void UProjectileAttackComponent::ShotBehaviour()
{
	UAttackComponent::ShotBehaviour();
	//SpawnProjectile();
}

void UProjectileAttackComponent::SetShotStats(TObjectPtr<AProjectile> _projectile, int _damage, float _speed, float _range)
{
	_projectile->SetDamage(_damage);
	_projectile->SetMoveSpeed(_speed);
	_projectile->SetRange(_range);
}

void UProjectileAttackComponent::SpawnProjectile(FRotator _rotator)
{
	//const FRotator _rotator = UKismetMathLibrary::FindLookAtRotation(owner->GetActorLocation(), target->GetActorLocation());
	TObjectPtr<AProjectile> _spawned =GetWorld()->SpawnActor<AProjectile>(classProjectileToSpawn, owner->GetActorLocation(), _rotator);
	_spawned->SetFolderPath("Spawned/Projectile");
	SetShotStats(_spawned, damage, projectileSpeed, owner->FindComponentByClass<UTargetComponent>()->GetRange()*1.1);
}


// Called every frame
void UProjectileAttackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

