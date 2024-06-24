// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TargetComponent.h"
#include "CloseTargetComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PERSONALTOWERDEFENSE_API UCloseTargetComponent : public UTargetComponent
{
	GENERATED_BODY()

		UPROPERTY(EditAnywhere)
		float timerSpeed = 0.2;
		UPROPERTY(EditAnywhere)
		FTimerHandle TimerCheckTarget;

public:	
	// Sets default values for this component's properties
	UCloseTargetComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void SetNewTarget()override;
	virtual void ChangeTarget()override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
