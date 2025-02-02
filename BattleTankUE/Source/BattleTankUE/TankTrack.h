// MBI Copyrights

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

class ASuspension;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKUE_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void AccelerateTrack(float Acceleration);

private:
	TArray<ASuspension*> GetSuspensions() const;

	void MoveTrack(float TrackAcceleration);

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	/* Maximum Force in Newtons that is applied by the Track to make the Tank move
	To set 1g acceleration on a 40 tonnes Tank we need about 400 000 Newtons
	Unreal base distance unit is centimeters */
	float BaseMovementForce = 37500000;

	UTankTrack();
};
