// CC0

#pragma once

#include "Engine/TriggerVolume.h"
#include "Components/ActorComponent.h"
#include "MonologTrigger.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMonologEvent);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEGAME_API UMonologTrigger : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMonologTrigger();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FMonologEvent OnWalk;

private:

	UPROPERTY(EditAnywhere)
	ATriggerVolume* MonologPlace = nullptr;

	AActor* Owner;
	bool IsActorOwnerlaping();
};
