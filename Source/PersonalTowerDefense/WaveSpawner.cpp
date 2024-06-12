// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveSpawner.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
AWaveSpawner::AWaveSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWaveSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AWaveSpawner::BeginPlay()
{
	Super::BeginPlay();
	InitLocToSpawn();
	GetWorld()->GetTimerManager().SetTimer(TimerSpawn, this, &AWaveSpawner::Spawn, spawnDelay, true);
}

void AWaveSpawner::Spawn()
{
	if (actualNumberSpawn >= numberMaxToSpawn)return;
	GetWorld()->GetTimerManager().SetTimer(TimerSpawnOne,this, &AWaveSpawner::SpawnOne, spawnOneDelay, true,spawnOneDelay);
}

void AWaveSpawner::SpawnOne()
{	
	TObjectPtr<AActor> _spawned = GetWorld()->SpawnActor<AActor>(classToSpawn, locToSpawn, FRotator::ZeroRotator);
	TObjectPtr<ABaseEnemy> _enemy = Cast<ABaseEnemy>(_spawned);
	if (!_enemy)return;
	actualNumberSpawn++;
	onEnemySpawned.Broadcast(_enemy.Get());
	allEnemy.Add(_enemy);
	onEnemyListUpdated.Broadcast(allEnemy);

	actualGroupSpawn++;
	if (actualGroupSpawn >= groupSize) {
		GetWorld()->GetTimerManager().ClearTimer(TimerSpawnOne);
		actualGroupSpawn = 0;
	}
}

void AWaveSpawner::InitLocToSpawn()
{
	TArray<TObjectPtr<AActor>>_tempList;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), checkpointClass, _tempList);
	int _size = _tempList.Num();
	for (int i = 0; i < _size; i++)
	{
		TObjectPtr<ACheckPoint> _point = Cast<ACheckPoint>(_tempList[i]);
		if (_point->GetCheckpointNumber() == 0)locToSpawn = _point->GetActorLocation();
	}
}

// Called every frame

