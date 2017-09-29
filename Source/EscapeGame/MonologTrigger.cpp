// CC0

#include "MonologTrigger.h"
#include "Gameframework/Actor.h"
#include "Classes/Components/PrimitiveComponent.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UMonologTrigger::UMonologTrigger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMonologTrigger::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();
	if (!MonologPlace)
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing MonologPlace"), *GetOwner()->GetName());

	}
}


// Called every frame
void UMonologTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll Trigger Volume
	if (IsActorOwnerlaping())
	{
		OnWalk.Broadcast();
	}

}

bool UMonologTrigger::IsActorOwnerlaping()
{
	float TotalMass = 0.f;
	//Find all overlapping actors
	TArray<AActor*> OverlappingActors;
	if (!MonologPlace) { return false; }
	MonologPlace->GetOverlappingActors(OUT OverlappingActors);
	return OverlappingActors.Contains(Owner);
}

