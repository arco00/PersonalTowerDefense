// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CheckPoint.h"
#include "MoveComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PERSONALTOWERDEFENSE_API UMoveComponent : public UActorComponent
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
			TArray<TObjectPtr<ACheckPoint>> listCheckpoint;
		UPROPERTY(EditAnywhere)
			TSubclassOf<ACheckPoint> checkpointClass = nullptr;
		UPROPERTY(EditAnywhere)
			TObjectPtr<AActor> owner = nullptr;
		UPROPERTY(EditAnywhere)
			int actualCheckpoints = 0;
		UPROPERTY(EditAnywhere)
			float speed = 200;
		UPROPERTY(EditAnywhere)
			bool canMove = true;
		


public:	
	// Sets default values for this component's properties
	UMoveComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	void Init();
	void MakeListCheckpoint();
	void SortListcheckpoint();
	void Move();
	bool CheckAsArrived(FVector _end);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
