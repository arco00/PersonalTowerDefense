// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveComponent.h"
#include "BaseEnemy.generated.h"

USTRUCT()
struct FWeakness
{
	GENERATED_BODY()
public:
		UPROPERTY(EditAnywhere)
		float fireResistance = 1;
		FWeakness(){		};

		FWeakness(int _fireResistance) 
		{
			_fireResistance = fireResistance;
		}

};

class AEnemyManager;
UCLASS()
class PERSONALTOWERDEFENSE_API ABaseEnemy : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UMoveComponent> move = nullptr;
	UPROPERTY(EditAnywhere)
		int health = 100;
	

	UPROPERTY(EditAnywhere)
		TObjectPtr<AEnemyManager> manager = nullptr;
	
public:	
	// Sets default values for this actor's properties
	ABaseEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Death();
	void Init();
	void DebugLife();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void AddHealth(int _added);
	int GetHealth() { return health; }

};
