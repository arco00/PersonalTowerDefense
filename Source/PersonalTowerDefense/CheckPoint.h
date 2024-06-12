// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BillboardComponent.h"
#include "CheckPoint.generated.h"

UCLASS()
class PERSONALTOWERDEFENSE_API ACheckPoint : public AActor
{
	GENERATED_BODY()
		//be precise with the order
	
	UPROPERTY(EditAnywhere)
		int checkpointNumber = 0;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UBillboardComponent> billboard = nullptr;
	
public:	
	// Sets default values for this actor's properties
	ACheckPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	int GetCheckpointNumber() { return checkpointNumber; }

};
