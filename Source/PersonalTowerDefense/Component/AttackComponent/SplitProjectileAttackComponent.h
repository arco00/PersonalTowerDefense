// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectileAttackComponent.h"
#include "SplitProjectileAttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PERSONALTOWERDEFENSE_API USplitProjectileAttackComponent : public UProjectileAttackComponent
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		int projectileNumber = 5;
	UPROPERTY(EditAnywhere)
		float shotAngle = 90;


public:	
	// Sets default values for this component's properties
	USplitProjectileAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void ShotBehaviour() override;
	


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
