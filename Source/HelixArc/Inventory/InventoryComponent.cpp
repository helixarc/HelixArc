// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include <HelixArc/Core/HelixArcGameInstance.h>
#include <HelixArc/Items/ItemData.h>
#include <HelixArc/Items/ItemsDatabase.h>

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SetIsReplicatedByDefault(true);
}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UInventoryComponent::AddItemByID(int ItemID)
{
	if (!GetOwner()->HasAuthority())
	{
		return Server_AddItemByID(ItemID);
	}

	UHelixArcGameInstance* GameInstance = Cast<UHelixArcGameInstance>(GetWorld()->GetGameInstance());
	if (GameInstance)
	{
		FItemInstance ItemInstance;
		UItemData** ItemData = GameInstance->ItemDatabase->Items.Find(ItemID);
		if (ItemData != nullptr)
		{
			ItemInstance.ParentItemID = (*ItemData)->ItemID;
			Inventory.AddUnique(ItemInstance);
		}
	}

	OnInventoryUpdated.Broadcast();
}

void UInventoryComponent::Server_AddItemByID_Implementation(int ItemID)
{
	return AddItemByID(ItemID);
}

bool UInventoryComponent::Server_AddItemByID_Validate(int ItemID)
{
	return true;
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

