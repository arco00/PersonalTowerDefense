// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ProjectileAttackComponent.h"
#include "OneProjectileAttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PERSONALTOWERDEFENSE_API UOneProjectileAttackComponent : public UProjectileAttackComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOneProjectileAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void ShotBehaviour() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
