// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"
#include "PersonalTowerDefense/Spawned/Enemy/BaseEnemy.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AProjectile::HitBehaviour);
}

void AProjectile::Move()
{
	SetActorLocation(GetActorLocation()+GetActorForwardVector()*moveSpeed*GetWorld()->DeltaTimeSeconds);
	actualDist += (GetActorForwardVector() * moveSpeed * GetWorld()->DeltaTimeSeconds).Size();
	if (actualDist >= maxDist)Destroy();
}

void AProjectile::HitBehaviour(AActor* _this, AActor* _hitted)
{
	//UE_LOG(LogTemp, Warning, TEXT("overlapp"));
	_this->Destroy();
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

