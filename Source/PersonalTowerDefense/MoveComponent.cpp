// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UMoveComponent::UMoveComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoveComponent::BeginPlay()
{
	Super::BeginPlay();
	Init();

	// ...
	
}

void UMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (canMove)Move();

}

void UMoveComponent::Init()
{
	MakeListCheckpoint();
	SortListcheckpoint();
	owner = GetOwner();
}

void UMoveComponent::MakeListCheckpoint()
{
	TArray<TObjectPtr<AActor>>_tempList;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), checkpointClass,_tempList );
	int _size = _tempList.Num();
	for (size_t i = 0; i < _size; i++)
	{
		listCheckpoint.Add(Cast<ACheckPoint>(_tempList[i]));
	}
}

void UMoveComponent::SortListcheckpoint()
{
	int _i = 0;
	int _size = listCheckpoint.Num();
	while ( _i < _size)
	{
		listCheckpoint.Swap(_i, listCheckpoint[_i]->GetCheckpointNumber());
		if (listCheckpoint[_i]->GetCheckpointNumber() == _i)(_i++);
	}
}

void UMoveComponent::Move()
{
	if (listCheckpoint.Num() <= 1 )return;
	FVector _start = owner->GetActorLocation();
	FVector _end = listCheckpoint[actualCheckpoints+1]->GetActorLocation();
	FVector _newLoc = FMath::VInterpConstantTo(_start, _end,GetWorld()->DeltaTimeSeconds,speed);
	owner->SetActorLocation(_newLoc);
	if (CheckAsArrived(_end)) {
		actualCheckpoints++;
		if (actualCheckpoints == listCheckpoint.Num()-1) canMove = false;
	}

}

bool UMoveComponent::CheckAsArrived(FVector _end)
{
	return FVector::Dist(owner->GetActorLocation(), _end) < 100;
}


