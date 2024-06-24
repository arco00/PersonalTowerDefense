// Fill out your copyright notice in the Description page of Project Settings.


#include "WaveSpawner.h"
#include <Kismet/GameplayStatics.h>
#include "EnemyManager.h"
#include "PersonalTowerDefense/GameModeBaseLevel.h"

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
	Init();
}

void AWaveSpawner::Spawn()
{
	if (actualGroupSpawn >= numberGroupToSpawn)return;
	GetWorld()->GetTimerManager().SetTimer(TimerSpawnOne,this, &AWaveSpawner::SpawnOne, spawnOneDelay, true,spawnOneDelay);
}

void AWaveSpawner::SpawnOne()
{	
	TObjectPtr<AActor> _spawned = GetWorld()->SpawnActor<AActor>(classToSpawn, locToSpawn, FRotator::ZeroRotator);
	TObjectPtr<ABaseEnemy> _enemy = Cast<ABaseEnemy>(_spawned);
	_enemy->SetFolderPath("Spawned/Enemy");
	if (!_enemy) return;
	//UE_LOG(LogTemp, Warning, TEXT("Cast spawn failed"));
	actualGroupSize++;
	if (actualGroupSize >= groupSize)
	{
		GetWorld()->GetTimerManager().ClearTimer(TimerSpawnOne);
		actualGroupSpawn ++;
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
		if (_point->GetCheckpointNumber() == 0) { 
			locToSpawn = _point->GetActorLocation();
			return;
		}
	}
}

void AWaveSpawner::Init()
{
	InitLocToSpawn();
	GetWorld()->GetTimerManager().SetTimer(TimerSpawn, this, &AWaveSpawner::Spawn, spawnGroupDelay, true);
	TObjectPtr<AGameModeBaseLevel> _gm = GetWorld()->GetAuthGameMode<AGameModeBaseLevel>();
	if (!_gm)return;
	manager = _gm->GetEnemyManager();
	if (!manager)return;
}



