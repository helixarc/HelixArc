// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/ALSBaseCharacter.h"
#include <HelixArc/Inventory/InteractionComponent.h>
#include "HelixArcCharacter.generated.h"

/**
 * 
 */
UCLASS()
class HELIXARC_API AHelixArcCharacter : public AALSBaseCharacter
{
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory")
		FInteractionData ItemInView;

		
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void CheckView();

	void Interact();
	
};
