// Fill out your copyright notice in the Description page of Project Settings.


#include "PersonalTowerDefense/Component/TargetComponent/TargetComponent.h"
#include "Engine.h"
#include "PersonalTowerDefense/GameModeBaseLevel.h"
#include "PersonalTowerDefense/Manager/EnemyManager.h"

// Sets default values for this component's properties
UTargetComponent::UTargetComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
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
	//DebugRange();
	DebugTarget();
}

void UTargetComponent::SetNewTarget()
{

	// for children
}

void UTargetComponent::ChangeTarget()
{
	//for children
	
}

void UTargetComponent::SetNewTargetList(TArray<ABaseEnemy*> _list)
{

	//UE_LOG(LogTemp, Warning, TEXT("newlisttarget"));
	targetList.Empty();
	
	/*for (int i = 0; i < _size; i++)
	{
		if (!_list[i])break;
		FVector _newTargetPos = _list[i]->GetActorLocation();
		if (FVector::Dist(_newTargetPos,owner->GetActorLocation())<=range) 
		{
			targetList.Add(_list[i]);
		}
	}*/

	TArray<FHitResult> _results;
	const bool _hit = UKismetSystemLibrary::SphereTraceMultiForObjects(this, owner->GetActorLocation(), owner->GetActorLocation()
	, range,typeToTarget, false, typeToIgnore, EDrawDebugTrace::ForDuration, _results, true, FLinearColor::Red, FLinearColor::Green, 5);
	int _size =_results.Num() ;
	for (int i = 0; i < _size; i++)
	{
		targetList.Add(Cast<ABaseEnemy>(_results[i].GetActor()));
	}
	SetNewTarget();
}

void UTargetComponent::Init()
{
	owner=GetOwner();
	TObjectPtr<AGameModeBaseLevel> _gm = GetWorld()->GetAuthGameMode<AGameModeBaseLevel>();
	if (!_gm)return;
	manager = _gm->GetEnemyManager();
	if (!manager)return;
	UE_LOG(LogTemp, Warning, TEXT("init"));

	manager->OnEnemyListUpdated().AddDynamic(this, &UTargetComponent::SetNewTargetList);
}


void UTargetComponent::DebugRange() 
{
	DrawDebugSphere(GetWorld(),owner->GetActorLocation(),range,10,FColor::Black,false,-1,0,10);
}

void UTargetComponent::DebugTarget()
{
	if (!IsValid(actualTarget))return;
	FVector _pos = actualTarget->GetActorLocation() + actualTarget->GetActorUpVector() * 200;
	DrawDebugSphere(GetWorld(),_pos, 30, 10, debugTargetColor, false, -1, 0, 10);
}