// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class PERSONALTOWERDEFENSE_API AProjectile : public AActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
		float moveSpeed = 600;
	UPROPERTY(EditAnywhere)
		float actualDist = 0;
	UPROPERTY(EditAnywhere)
		float maxDist = 500;
	UPROPERTY(EditAnywhere)
		int damage=10;
	
	UPROPERTY(EditAnywhere)
		TObjectPtr<UStaticMeshComponent> mesh = nullptr;


public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void Move();
	UFUNCTION()
	virtual void HitBehaviour(AActor* _this, AActor* _hitted);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SetRange(const float _maxDist) { maxDist = _maxDist; }
	void SetDamage(const int _damage) { damage = _damage; }
	void SetMoveSpeed(const float _moveSpeed) { moveSpeed = _moveSpeed; }

};
