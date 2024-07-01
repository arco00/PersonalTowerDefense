// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Spawned/Tower/BaseTower.h"
#include "HUDPlay.generated.h"

/**
 * 
 */
UCLASS()
class PERSONALTOWERDEFENSE_API AHUDPlay : public AHUD
{
	GENERATED_BODY()
protected:
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TObjectPtr<ABaseTower> selectedTower = nullptr;

public:
 TObjectPtr<ABaseTower> GetSelectedTower() { return selectedTower; }
 void SetSelectedTower(TObjectPtr<ABaseTower> _tower) { selectedTower=_tower; }
	
};
