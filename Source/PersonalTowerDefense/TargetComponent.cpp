// Fill out your copyright notice in the Description page of Project Settings.


#include "TargetComponent.h"
#include "WaveSpawner.h"

// Sets default values for this component's properties
UTargetComponent::UTargetComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTargetComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();

}

void UTargetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTargetComponent::SetNewTarget()
{
	int _size = targetList.Num();
	if (_size <= 0)return;
	if (!actualTarget)actualTarget = targetList[0];
	FVector _actualTargetLoc = actualTarget->GetActorLocation();
	for (int i = 0; i < _size; i++)
	{
		FVector _newTargetLoc = targetList[i]->GetActorLocation();
		if (FVector::Dist(_newTargetLoc, owner->GetActorLocation())< FVector::Dist(_actualTargetLoc, owner->GetActorLocation()))
		{
			actualTarget = targetList[i];
			_actualTargetLoc = actualTarget->GetActorLocation();
		}
	}
	newTarget.Broadcast(actualTarget);
}

void UTargetComponent::SetNewTargetList(TArray<ABaseEnemy*> _list)
{
	targetList.Empty();
	int _size =_list.Num() ;
	for (int i = 0; i < _size; i++)
	{
		FVector _newTargetPos = _list[i]->GetActorLocation();
		if (FVector::Dist(_newTargetPos,owner->GetActorLocation())<=range) 
		{
			targetList.Add(_list[i]);
		}
	}
}

void UTargetComponent::Init()
{
	Cast<AWaveSpawner>(this)->OnEnemyListUpdated().AddDynamic(this, &UTargetComponent::SetNewTargetList);
	owner=GetOwner();
}


// Called every frame

