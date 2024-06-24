// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include <PersonalTowerDefense/Manager/EnemyManager.h>
#include "ExplosiveProjectile.generated.h"


UCLASS()
class PERSONALTOWERDEFENSE_API AExplosiveProjectile : public AProjectile
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		float explosionRange = 200;
	UPROPERTY(EditAnywhere)
		TObjectPtr<AEnemyManager> manager = nullptr;
	
public:	
	// Sets default values for this actor's properties
	AExplosiveProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void HitBehaviour(AActor* _this, AActor* _hitted);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
