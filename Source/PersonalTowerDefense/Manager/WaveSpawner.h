// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PersonalTowerDefense/Spawned/Enemy/BaseEnemy.h"
#include "WaveSpawner.generated.h"

class AEnemyManager;
UCLASS()
class PERSONALTOWERDEFENSE_API AWaveSpawner : public AActor
{
	GENERATED_BODY()

	//DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemySpawned, ABaseEnemy*, _spawned);
	

	/*UPROPERTY()
		FOnEnemySpawned onEnemySpawned;*/
	
	

	UPROPERTY(EditAnywhere)
		float spawnGroupDelay = 1;
	UPROPERTY(EditAnywhere)
		float spawnOneDelay = 1;
	UPROPERTY(EditAnywhere)
		FTimerHandle TimerSpawn;
	UPROPERTY(EditAnywhere)
		FTimerHandle TimerSpawnOne;

	UPROPERTY(EditAnywhere)
		int groupSize = 1;
	UPROPERTY(EditAnywhere)
		int numberGroupToSpawn = 5;
	UPROPERTY(EditAnywhere)
		int actualGroupSize = 0;
	UPROPERTY(EditAnywhere)
		int actualGroupSpawn = 0;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABaseEnemy> classToSpawn = nullptr;
	UPROPERTY(EditAnywhere)
		FVector locToSpawn = FVector(0);
	

	UPROPERTY(EditAnywhere)
		TSubclassOf<ACheckPoint> checkpointClass = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<AEnemyManager> manager = nullptr;
	

	
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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//FOnEnemySpawned& OnEnemySpawned() { return onEnemySpawned; }
	
	

};
