// Fill out your copyright notice in the Description page of Project Settings.


#include "HelixArcCharacter.h"

void AHelixArcCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CheckView();
}

void AHelixArcCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AHelixArcCharacter::Interact);
}

void AHelixArcCharacter::CheckView()
{
	FVector CamLoc;
	FRotator CamRot;
	Controller->GetPlayerViewPoint(CamLoc, CamRot);

	FVector Start = CamLoc;
	FVector End = Start + CamRot.Vector() * 500.f;

	FHitResult Hit;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, Params))
	{
		if (Hit.GetActor() && Hit.GetActor()->FindComponentByClass<UInteractionComponent>())
		{
			ItemInView.Actor = Hit.GetActor();
			ItemInView.InteractionText = Hit.GetActor()->FindComponentByClass<UInteractionComponent>()->InteractionText;
		}
		else
		{
			ItemInView.Actor = nullptr;
			ItemInView.InteractionText = FText::FromString("");
		}
	}
	else
	{
		ItemInView.Actor = nullptr;
		ItemInView.InteractionText = FText::FromString("");
	}
}

void AHelixArcCharacter::Interact()
{
	if (ItemInView.Actor)
	{
		ItemInView.Actor->FindComponentByClass<UInteractionComponent>()->Interact(this);
	}
}