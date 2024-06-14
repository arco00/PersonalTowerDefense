// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TargetComponent.h"
#include "AttackComponent.h"
#include "BaseTower.generated.h"

UCLASS()
class PERSONALTOWERDEFENSE_API ABaseTower : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UAttackComponent> attackComponent = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UTargetComponent> targetComponent = nullptr;
	
public:	
	// Sets default values for this actor's properties
	ABaseTower();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
