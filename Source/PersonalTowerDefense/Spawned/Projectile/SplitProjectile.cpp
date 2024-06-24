// Fill out your copyright notice in the Description page of Project Settings.


#include "SplitProjectile.h"

// Sets default values
ASplitProjectile::ASplitProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASplitProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASplitProjectile::HitBehaviour(AActor* _this, AActor* _hitted)
{
	AProjectile::HitBehaviour(_this, _hitted);
	for (int i = 0; i < numberProjectile; i++)
	{
		const FRotator _rotator = FRotator(0, 360 / numberProjectile * i, 0);
		const TObjectPtr<AProjectile> _spawned = GetWorld()->SpawnActor<AProjectile>(classProjectileToSpawn, GetActorLocation(), _rotator);
		_spawned->SetFolderPath("Spawned/Projectile");
		_spawned->SetDamage(damageSmall);
		_spawned->SetMoveSpeed(speedSmall);
		_spawned->SetRange(rangeSmall);
	}

}

// Called every frame
void ASplitProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

