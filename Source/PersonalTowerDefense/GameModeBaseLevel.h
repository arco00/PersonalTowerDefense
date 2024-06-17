// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameModeBaseLevel.generated.h"

class AEnemyManager;

UCLASS()
class PERSONALTOWERDEFENSE_API AGameModeBaseLevel : public AGameModeBase
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere)
		TSubclassOf<AEnemyManager> enemyManagerToSpawn = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<AEnemyManager> enemyManager = nullptr;


public:
	TObjectPtr<AEnemyManager> GetEnemyManager() const { return enemyManager; }

protected:
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	void Init();
};
