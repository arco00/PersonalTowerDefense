// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PersonalTowerDefense/Spawned/Enemy/BaseEnemy.h"
#include "TargetComponent.generated.h"

class AEnemeyManager;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PERSONALTOWERDEFENSE_API UTargetComponent : public UActorComponent
{
	GENERATED_BODY()
		DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FNewTarget, ABaseEnemy*, _target);

protected :
	UPROPERTY(EditAnywhere)
		FNewTarget newTarget;


	UPROPERTY(EditAnywhere)
		bool hasTarget = false;
	UPROPERTY(EditAnywhere)
		float range = 500;
	UPROPERTY(EditAnywhere)
		TObjectPtr<AActor> owner = nullptr;
	UPROPERTY(EditAnywhere)
		ABaseEnemy* actualTarget = nullptr;
	UPROPERTY(EditAnywhere)
		TArray <ABaseEnemy*> targetList;
	UPROPERTY(EditAnywhere)
		TObjectPtr<AEnemyManager> manager = nullptr;
	UPROPERTY(EditAnywhere)
		FColor debugTargetColor = FColor::Blue;

	UPROPERTY(EditAnywhere)
		TArray<TEnumAsByte<EObjectTypeQuery>> typeToTarget;
	UPROPERTY(EditAnywhere)
		TArray<TObjectPtr<AActor>> typeToIgnore;


public:	
	// Sets default values for this component's properties
	UTargetComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void SetNewTarget();
	virtual void ChangeTarget();
	virtual void Init();
	virtual void DebugRange();
	void DebugTarget();

	UFUNCTION()
	virtual void SetNewTargetList(TArray<ABaseEnemy*> _list);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	FNewTarget& NewTarget(){ return newTarget; }
	float GetRange() { return range; }

		
};
