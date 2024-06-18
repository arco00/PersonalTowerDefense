// Fill out your copyright notice in the Description page of Project Settings.


#include "MoreHealthTargetComponent.h"
#include "EnemyManager.h"
#include "BaseTower.h"

// Sets default values for this component's properties
UMoreHealthTargetComponent::UMoreHealthTargetComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UMoreHealthTargetComponent::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TimerCheckTarget, this, &UMoreHealthTargetComponent::ChangeTarget, timerSpeed, true, timerSpeed);
}

void UMoreHealthTargetComponent::SetNewTarget()
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
		if (actualTarget->GetHealth() < _enemy->GetHealth())
		{
			actualTarget = _enemy;
		}
	}
	newTarget.Broadcast(actualTarget);

}

void UMoreHealthTargetComponent::ChangeTarget()
{
	UTargetComponent::ChangeTarget();
	//test if we always can shot the target
	if (IsValid(actualTarget) && FVector::Dist(actualTarget->GetActorLocation(), owner->GetActorLocation()) <= range) return;
	//set new target
	SetNewTargetList(manager->GetEnemyList());
	
}


// Called every frame
void UMoreHealthTargetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


}

