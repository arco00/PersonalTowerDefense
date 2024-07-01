// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageProjectile.h"
#include "PersonalTowerDefense/Spawned/Enemy/BaseEnemy.h"

// Sets default values
ADamageProjectile::ADamageProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADamageProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADamageProjectile::HitBehaviour(AActor* _this, AActor* _hitted)
{
	AProjectile::HitBehaviour(_this, _hitted);
	TObjectPtr<ABaseEnemy> _target = Cast<ABaseEnemy>(_hitted);
	if (!IsValid(_target))return;
	_target->AddHealth(-damage);
}

// Called every frame
void ADamageProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

