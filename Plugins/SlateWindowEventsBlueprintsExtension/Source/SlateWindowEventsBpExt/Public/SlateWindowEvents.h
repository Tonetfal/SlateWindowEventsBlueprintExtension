// Author: Antonio Sidenko (Tonetfal), November 2024

#pragma once

#include "Subsystems/GameInstanceSubsystem.h"

#include "SlateWindowEvents.generated.h"

UCLASS()
class USlateWindowEvents
	: public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
		FOnApplicationWindowStateChangedSignature,
		bool, bIsActive);

public:
	//~UGameInstanceSubsystem Interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual bool ShouldCreateSubsystem(UObject* Outer) const override;
	//~End of UGameInstanceSubsystem Interface

	UFUNCTION(BlueprintPure)
	bool IsApplicationWindowActive() const;

private:
	void OnWindowFocusChanged(bool bIsActive);

public:
	UPROPERTY(BlueprintAssignable)
	FOnApplicationWindowStateChangedSignature OnApplicationWindowStateChanged;

public:
	bool bIsApplicationWindowActive = false;
};
