// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttackComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PERSONALTOWERDEFENSE_API UAttackComponent : public UActorComponent
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnShot);
	UPROPERTY(EditAnywhere)
		FOnShot onShot;

	UPROPERTY(EditAnywhere)
		int damage = 10;
	UPROPERTY(EditAnywhere)
		int salvoSize = 5;
	UPROPERTY(EditAnywhere)
		int actualShotFired = 0;

	UPROPERTY(EditAnywhere)
		float timeBetweenShot = 0.1;
	UPROPERTY(EditAnywhere)
		float timeBetweenSalvo = 2;
	UPROPERTY(EditAnywhere)
		float timeFromLastSalvo = 0;

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
	void ShotBehaviour();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	// Called every frame
	FOnShot& Onshot() { return onShot; }

};