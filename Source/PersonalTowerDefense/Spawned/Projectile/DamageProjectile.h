// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "DamageProjectile.generated.h"

UCLASS()
class PERSONALTOWERDEFENSE_API ADamageProjectile : public AProjectile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADamageProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void HitBehaviour(AActor* _this, AActor* _hitted);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
