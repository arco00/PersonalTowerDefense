// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TargetComponent.h"
#include "MoreHealthTargetComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PERSONALTOWERDEFENSE_API UMoreHealthTargetComponent : public UTargetComponent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		FTimerHandle TimerCheckTarget;
	UPROPERTY(EditAnywhere)
		float timerSpeed = 0.2;
	

public:	
	// Sets default values for this component's properties
	UMoreHealthTargetComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void SetNewTarget()override;
	virtual void ChangeTarget()override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
