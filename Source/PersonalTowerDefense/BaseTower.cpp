// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseTower.h"

// Sets default values
ABaseTower::ABaseTower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	attackComponent = CreateDefaultSubobject<UAttackComponent>("Attack");
	targetComponent = CreateDefaultSubobject<UTargetComponent>("Target");

	mesh->SetupAttachment(RootComponent);
	AddOwnedComponent(attackComponent);
	AddOwnedComponent(targetComponent);
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseTower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

