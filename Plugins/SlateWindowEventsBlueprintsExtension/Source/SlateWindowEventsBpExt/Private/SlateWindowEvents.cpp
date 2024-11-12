// Author: Antonio Sidenko (Tonetfal), November 2024

#include "SlateWindowEvents.h"

void USlateWindowEvents::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	auto& SlateApplication = FSlateApplication::Get();
	SlateApplication.OnApplicationActivationStateChanged().AddUObject(this, &ThisClass::OnWindowFocusChanged);
}

bool USlateWindowEvents::IsApplicationWindowActive() const
{
	return bIsApplicationWindowActive;
}

void USlateWindowEvents::OnWindowFocusChanged(bool bIsActive)
{
	bIsApplicationWindowActive = bIsActive;
	OnApplicationWindowStateChanged.Broadcast(bIsApplicationWindowActive);
}
