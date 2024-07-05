// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "HUDPlay.h"
#include "Kismet/KismetSystemLibrary.h"
#include <Kismet/GameplayStatics.h>
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"
#include <EnhancedInputComponent.h>
#include <EnhancedInputSubsystems.h>

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
	Init();
	//AActor*, TouchedActor , FKey, ButtonPressed
	
}

void APlayerPawn::ClicSelect(const FInputActionValue& _value)
{
	UE_LOG(LogTemp, Warning, TEXT("clic"));
	FVector _mouseLoc  ;
	FVector _mouseDirection ;
	
	bool getMousePos = GetWorld()->GetFirstPlayerController()->DeprojectMousePositionToWorld(_mouseLoc, _mouseDirection);
	UE_LOG(LogTemp, Warning, TEXT(" %i"), getMousePos);

	

	FHitResult _result;
	bool _hit = UKismetSystemLibrary::LineTraceSingleForObjects(this, _mouseLoc, _mouseLoc + _mouseDirection * 10000, objectType, false, toIgnore,
		EDrawDebugTrace::ForDuration, _result, true, FLinearColor::Red, FLinearColor::Green, 60.0);

	//_hit = GetWorld()->GetFirstPlayerController()->GetHitResultUnderCursor(ECC_Visibility, true, _result);

	UE_LOG(LogTemp, Warning, TEXT(" try"));
	if (!_hit)return;
	UE_LOG(LogTemp, Warning, TEXT(" hit"));

	UE_LOG(LogTemp, Warning, TEXT(" %s"),*_result.GetActor()->GetName());
	//mettre le _hit dans le hud
	//Cast<HUPlay>GetWorld()->GetFirstPlayerController()->GetHUD()
	TObjectPtr<AHUDPlay> _HUD = Cast<AHUDPlay>( GetWorld()->GetFirstPlayerController()->GetHUD());
	TObjectPtr<ABaseTower> _tower = Cast<ABaseTower>(_result.GetActor());
	_HUD->SetSelectedTower(_tower);
	
}

void APlayerPawn::Init()
{
	ULocalPlayer* _localPlayer = GetWorld()->GetFirstPlayerController()->GetLocalPlayer();
	if (!_localPlayer)return;
	UE_LOG(LogTemp, Warning, TEXT("local player compo ok"));
	UEnhancedInputLocalPlayerSubsystem* _inputSystem = _localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if (!_inputSystem)return;
	UE_LOG(LogTemp, Warning, TEXT("inputSystem compo ok"));
	_inputSystem->AddMappingContext(imc, 0);
}

FVector APlayerPawn::GetMouseLoc()
{
	float _mouseX;
	float _mouseY;
	UGameplayStatics::GetPlayerController(GetWorld(),0)->GetMousePosition(_mouseX, _mouseY);
	GetWorld()->GetFirstPlayerController()->GetMousePosition(_mouseX, _mouseY);
	UE_LOG(LogTemp, Warning, TEXT("Mouse Location: %f, %f"), _mouseX, _mouseY);
	return FVector(_mouseX, _mouseY,0);
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
	UE_LOG(LogTemp, Warning, TEXT("input compo ok"));
	_inputCompo->BindAction(clicAction, ETriggerEvent::Started, this, &APlayerPawn::ClicSelect);
}

