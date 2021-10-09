// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class HELIXARC_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		int ItemID;

	UPROPERTY(VisibleAnywhere, Category = "Interaction")
		class UInteractionComponent* InteractionComponent;

	UFUNCTION()
		void OnInteract(class AHelixArcCharacter* Player);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
