// Fill out your copyright notice in the Description page of Project Settings.


#include "ExplosiveProjectile.h"
#include <PersonalTowerDefense/GameModeBaseLevel.h>
#include "PersonalTowerDefense/Spawned/Enemy/BaseEnemy.h"
#include <Kismet/KismetSystemLibrary.h>

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
	
}

void AExplosiveProjectile::HitBehaviour(AActor* _this, AActor* _hitted)
{
	AProjectile::HitBehaviour(_this, _hitted);
	//DrawDebugSphere(GetWorld(), GetActorLocation(), explosionRange, 10, FColor::Red, false, 0.5, 0, 10);
	
	TArray<FHitResult> _results;
	const bool _hit = UKismetSystemLibrary::SphereTraceMultiForObjects(this, GetActorLocation(),GetActorLocation(), explosionRange,
		typeToDamage, false, typeToIgnore, EDrawDebugTrace::ForDuration, _results, true, FLinearColor::Red, FLinearColor::Green, 5);

	int _size = _results.Num();
		for (int i = 0; i < _size; i++)
		{
			TObjectPtr<ABaseEnemy> _enemy=Cast <ABaseEnemy>(_results[i].GetActor());
			_enemy->AddHealth(-damage);
		}

}

// Called every frame
void AExplosiveProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

