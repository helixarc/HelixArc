// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include <HelixArc/Inventory/InteractionComponent.h>
#include <HelixArc/Inventory/InventoryComponent.h>
#include <HelixArc/Player/HelixArcCharacter.h>

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractionComponent = CreateDefaultSubobject<UInteractionComponent>(TEXT("Interaction"));
	InteractionComponent->InteractionText = FText::FromString("Pickup");
}

void AItem::OnInteract(AHelixArcCharacter* Player)
{
	Player->InventoryComponent->AddItemByID(ItemID);
	Destroy();
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	InteractionComponent->OnInteract.AddDynamic(this, &AItem::OnInteract);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

