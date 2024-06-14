// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PERSONALTOWERDEFENSE_API UAttackComponent : public UActorComponent
{
	GENERATED_BODY()
	UPROPERTY()
		int damage = 10;
	UPROPERTY()
		int salvoSize = 5;
	UPROPERTY()
		int actualShotFired = 0;
	UPROPERTY()
		float timeBetweenShot = 0.1;
	UPROPERTY()
		float timeBetweenSalvo = 2;

	UPROPERTY(EditAnywhere)
		FTimerHandle TimerSalvo;
	UPROPERTY(EditAnywhere)
		FTimerHandle TimerShot;

	UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> owner = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<ABaseEnemy> target = nullptr;

public:	
	// Sets default values for this component's properties
	UAttackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION()
		void ActivateAttack(ABaseEnemy* _target);
	void Salvo();
	void Shot();
	void Init();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
