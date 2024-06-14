// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BaseEnemy.h"
#include "TargetComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PERSONALTOWERDEFENSE_API UTargetComponent : public UActorComponent
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNewTarget, ABaseEnemy*, _target);

	UPROPERTY(EditAnywhere)
		FNewTarget newTarget;


	UPROPERTY(EditAnywhere)
		bool hasTarget = false;
	UPROPERTY(EditAnywhere)
		float range = 500;
	UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> owner = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<ABaseEnemy> actualTarget = nullptr;
	UPROPERTY(EditAnywhere)
		TArray<TObjectPtr<ABaseEnemy>> targetList;


public:	
	// Sets default values for this component's properties
	UTargetComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void SetNewTarget();
	void Init();
	UFUNCTION()
	void SetNewTargetList(TArray<ABaseEnemy*> _list);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	FNewTarget& NewTarget(){ return newTarget; }

		
};
