// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveProjectile.h"
#include <PersonalTowerDefense/GameModeBaseLevel.h>
#include "PersonalTowerDefense/Spawned/Enemy/BaseEnemy.h"

// Sets default values
AExplosiveProjectile::AExplosiveProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AExplosiveProjectile::BeginPlay()
{
	Super::BeginPlay();
	TObjectPtr<AGameModeBaseLevel> _gm = GetWorld()->GetAuthGameMode<AGameModeBaseLevel>();
	if (!_gm)return;
	manager = _gm->GetEnemyManager();
	if (!manager)return;
}

void AExplosiveProjectile::HitBehaviour(AActor* _this, AActor* _hitted)
{
	AProjectile::HitBehaviour(_this, _hitted);
	const TArray<ABaseEnemy*> _enemyList = manager->GetEnemyList();
	const int _size = _enemyList.Num();
	DrawDebugSphere(GetWorld(), GetActorLocation(), explosionRange, 10, FColor::Red, false, 0.5, 0, 10);
	for (int i = 0; i < _size; i++)
	{
		if (FVector::Dist(GetActorLocation(), _enemyList[i]->GetActorLocation()) <= explosionRange) 
		{
			_enemyList[i]->AddHealth(-damage);
		}
	}
}

// Called every frame
void AExplosiveProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

