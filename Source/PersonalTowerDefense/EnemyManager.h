// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyManager.generated.h"

class ABaseEnemy;
UCLASS()
class PERSONALTOWERDEFENSE_API AEnemyManager : public AActor
{
	GENERATED_BODY()
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyListUpdated, TArray<ABaseEnemy*>, _allSpawned);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyDestroy, ABaseEnemy*, _destroyed);

	UPROPERTY()
		FOnEnemyListUpdated onEnemyListUpdated;
	UPROPERTY()
		FOnEnemyDestroy onEnemyDestroy;

	UPROPERTY(EditAnywhere)
		TArray<ABaseEnemy*> enemyList;
	
public:	
	// Sets default values for this actor's properties
	AEnemyManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AddEnemy(ABaseEnemy* _newEnemy);
	void RemoveEnemy(ABaseEnemy* _removedEnemy);
	TArray<ABaseEnemy*> GetEnemyList() { return enemyList; }


	FOnEnemyListUpdated& OnEnemyListUpdated() { return onEnemyListUpdated; }
	FOnEnemyDestroy& OnEnemyDestroy() { return onEnemyDestroy; }
	
};
