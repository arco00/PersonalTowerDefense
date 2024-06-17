// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"
#include "EnemyManager.h"
#include "GameModeBaseLevel.h"

// Sets default values
ABaseEnemy::ABaseEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	move = CreateDefaultSubobject<UMoveComponent>("Move");

	mesh->SetupAttachment(RootComponent);
	AddOwnedComponent(move);

}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	Init();
	
}

void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseEnemy::Death()
{
	UE_LOG(LogTemp, Warning, TEXT("dead"));
	//spawnerRef->OnEnemyDestroy().Broadcast(this);
	manager->RemoveEnemy(this);
	this->Destroy();
}

void ABaseEnemy::Init()
{
	TObjectPtr<AGameModeBaseLevel> _gm = GetWorld()->GetAuthGameMode<AGameModeBaseLevel>();
	if (!_gm)return;
	manager = _gm->GetEnemyManager();
	if (!manager)return;
	manager->AddEnemy(this);
}


void ABaseEnemy::AddHealth(int _added)
{
	health += _added;
	if (health <= 0)Death();
}

