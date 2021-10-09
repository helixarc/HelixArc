// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

//Called when the inventory is changed and the UI needs to update
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

USTRUCT(BlueprintType)
struct FItemInstance
{
	GENERATED_BODY()

	//What is this item's ID in the item database?
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int ParentItemID;

	//What is the current stack size of this instance?
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int StackSize = 0;

	bool operator==(const FItemInstance& OtherItem) const
	{
		return ParentItemID == OtherItem.ParentItemID;
	}
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class HELIXARC_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Inventory")
		TArray<FItemInstance> Inventory;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
		FOnInventoryUpdated OnInventoryUpdated;

	UFUNCTION(BlueprintCallable, Category = "Inventory|Add")
		void AddItemByID(int ItemID);

	UFUNCTION(Server, Reliable, WithValidation, Category = "Inventory|Add")
		void Server_AddItemByID(int ItemID);

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
