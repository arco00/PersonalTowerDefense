// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseEnemy.h"
#include "WaveSpawner.generated.h"

UCLASS()
class PERSONALTOWERDEFENSE_API AWaveSpawner : public AActor
{
	GENERATED_BODY()

	//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemySpawned, ABaseEnemy*, _spawned);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyListUpdated, TArray<ABaseEnemy*>, _allSpawned);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyDestroy, ABaseEnemy*, _destroyed);

	/*UPROPERTY()
		FOnEnemySpawned onEnemySpawned;*/
	UPROPERTY()
		FOnEnemyListUpdated onEnemyListUpdated;
	UPROPERTY()
		FOnEnemyDestroy onEnemyDestroy;

	UPROPERTY(EditAnywhere)
		float spawnDelay = 1;
	UPROPERTY(EditAnywhere)
		float spawnOneDelay = 1;
	UPROPERTY(EditAnywhere)
		int groupSize = 1;
	UPROPERTY(EditAnywhere)
		int numberMaxToSpawn = 5;
	UPROPERTY(EditAnywhere)
		int actualNumberSpawn = 0;
	UPROPERTY(EditAnywhere)
		int actualGroupSpawn = 0;
	UPROPERTY(EditAnywhere)
		FTimerHandle TimerSpawn;
	UPROPERTY(EditAnywhere)
		FTimerHandle TimerSpawnOne;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseEnemy> classToSpawn = nullptr;
	UPROPERTY(EditAnywhere)
		FVector locToSpawn = FVector(0);
	UPROPERTY(EditAnywhere)
		TArray<TObjectPtr<ABaseEnemy>> allEnemy;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ACheckPoint> checkpointClass = nullptr;
	

	
public:	
	// Sets default values for this actor's properties
	AWaveSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void InitLocToSpawn();
	void Init();

	UFUNCTION()
	void Spawn();
	UFUNCTION()
	void SpawnOne();
	UFUNCTION()
	void RemoveFromEnemyList(ABaseEnemy* _destroy);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//FOnEnemySpawned& OnEnemySpawned() { return onEnemySpawned; }
	FOnEnemyListUpdated& OnEnemyListUpdated() { return onEnemyListUpdated; }
	FOnEnemyDestroy& OnEnemyDestroy() { return onEnemyDestroy; }

};
