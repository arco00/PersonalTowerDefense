// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyManager.h"
#include "BaseEnemy.h"

// Sets default values
AEnemyManager::AEnemyManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyManager::AddEnemy(ABaseEnemy* _newEnemy)
{
	if (!_newEnemy)return;
	//UE_LOG(LogTemp, Warning, TEXT("add list enemy"));
	enemyList.Add(_newEnemy);
	onEnemyListUpdated.Broadcast(enemyList);
}

void AEnemyManager::RemoveEnemy( ABaseEnemy* _removedEnemy)
{
	if (!IsValid(_removedEnemy))return;
	UE_LOG(LogTemp, Warning, TEXT("remove list enemy"));
	enemyList.Remove(_removedEnemy);
	onEnemyListUpdated.Broadcast(enemyList);

}

