// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include <Camera/CameraComponent.h>
#include "InputMappingContext.h"
#include "PlayerPawn.generated.h"

UCLASS()
class PERSONALTOWERDEFENSE_API APlayerPawn : public APawn
{
	GENERATED_BODY()
		UPROPERTY(EditAnywhere)
		TObjectPtr<UCameraComponent> camera = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UInputMappingContext> imc = nullptr;
	UPROPERTY(EditAnywhere)
		TObjectPtr<UInputAction> clicAction = nullptr;
	UPROPERTY(EditAnywhere)
		FVector mouseLocation = FVector::ZeroVector;
	UPROPERTY(EditAnywhere)
		TArray<TEnumAsByte<EObjectTypeQuery>> objectType;
	UPROPERTY(EditAnywhere)
		TArray<TObjectPtr<AActor>> toIgnore;
	
	

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void ClicSelect(const FInputActionValue& _value);
	void Init();
	FVector GetMouseLoc();
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
