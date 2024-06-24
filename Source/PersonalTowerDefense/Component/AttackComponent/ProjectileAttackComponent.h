// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttackComponent.h"
#include <PersonalTowerDefense/Spawned/Projectile/Projectile.h>
#include "ProjectileAttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PERSONALTOWERDEFENSE_API UProjectileAttackComponent : public UAttackComponent
{
	GENERATED_BODY()
protected:
		UPROPERTY(EditAnywhere)
		float projectileSpeed = 600;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AProjectile> classProjectileToSpawn = nullptr;

public:	
	// Sets default values for this component's properties
	UProjectileAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void ShotBehaviour() override;
	virtual void SetShotStats(TObjectPtr<AProjectile> _projectile ,int _damage, float _speed, float _range);
	virtual void SpawnProjectile(FRotator _rotator);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
