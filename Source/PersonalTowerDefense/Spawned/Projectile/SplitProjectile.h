// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DamageProjectile.h"
#include "SplitProjectile.generated.h"

UCLASS()
class PERSONALTOWERDEFENSE_API ASplitProjectile : public ADamageProjectile
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		int numberProjectile = 8;
	UPROPERTY(EditAnywhere)
		int damageSmall = 5;
	UPROPERTY(EditAnywhere)
		float speedSmall = 600;
	UPROPERTY(EditAnywhere)
		float rangeSmall = 100;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AProjectile> classProjectileToSpawn = nullptr;
	
public:	
	// Sets default values for this actor's properties
	ASplitProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void HitBehaviour(AActor* _this, AActor* _hitted) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
