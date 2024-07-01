// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include <EnhancedInputSubsystems.h>
#include <EnhancedInputComponent.h>
#include "Kismet/KismetSystemLibrary.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	camera->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	//AActor*, TouchedActor , FKey, ButtonPressed
	
}

void APlayerPawn::ClicSelect(const FInputActionValue& _value)
{
	UE_LOG(LogTemp, Warning, TEXT("clic"));
	FHitResult _result;
	//FVector _mouseLocation = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(mouseX, mouseY);
	UKismetSystemLibrary::LineTraceSingleForObjects(this, GetActorLocation(), mouseLocation, objectType, false, toIgnore,
		EDrawDebugTrace::ForDuration, _result, true, FLinearColor::Red, FLinearColor::Green, 1);
}



// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* _inputCompo = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!_inputCompo) return;
	UE_LOG(LogTemp, Warning, TEXT("imput compo ok"));
	_inputCompo->BindAction(clic, ETriggerEvent::Started, this, &APlayerPawn::ClicSelect);

}

