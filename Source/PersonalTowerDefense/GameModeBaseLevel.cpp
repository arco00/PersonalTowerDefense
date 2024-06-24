// Fill out your copyright notice in the Description page of Project Settings.


#include "GameModeBaseLevel.h"
#include "PersonalTowerDefense/Manager/EnemyManager.h"

void AGameModeBaseLevel::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) {
	Super::InitGame(MapName, Options, ErrorMessage);
	Init();
}


void AGameModeBaseLevel::Init() {

	if (!enemyManager) 
	{
		enemyManager = GetWorld()->SpawnActor<AEnemyManager>(enemyManagerToSpawn);
	}
}


