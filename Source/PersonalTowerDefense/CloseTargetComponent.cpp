// Fill out your copyright notice in the Description page of Project Settings.


#include "CloseTargetComponent.h"
#include "EnemyManager.h"

// Sets default values for this component's properties
UCloseTargetComponent::UCloseTargetComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

	


// Called when the game starts
	void UCloseTargetComponent::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TimerCheckTarget, this, &UCloseTargetComponent::ChangeTarget, timerSpeed, true, timerSpeed);
}

void UCloseTargetComponent::SetNewTarget()
{
	UTargetComponent::SetNewTarget();

	UE_LOG(LogTemp, Warning, TEXT("testSetTarget"));

	if (targetList.Num() < 1) {
		actualTarget = nullptr;
		return;
	}
	
	if (!IsValid(actualTarget)) actualTarget = targetList[0];
	for (int i = 0; i < targetList.Num(); i++)
	{
		ABaseEnemy* _enemy = targetList[i];
		float _newDistance = FVector::Dist(_enemy->GetActorLocation(), owner->GetActorLocation());
		float _currentDistance = FVector::Dist(actualTarget->GetActorLocation(), owner->GetActorLocation());
		if (_newDistance < _currentDistance) 
		{
			actualTarget = _enemy;
		}
	}
	newTarget.Broadcast(actualTarget);
}

void UCloseTargetComponent::ChangeTarget()
{
	UTargetComponent::ChangeTarget();
	//if (FVector::Dist(actualTarget->GetActorLocation(), owner->GetActorLocation()) >= range)
	SetNewTargetList(manager->GetEnemyList());
}


// Called every frame
void UCloseTargetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

