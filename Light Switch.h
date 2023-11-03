// LightSwitch.h


#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightSwitch.generated.h"


UCLASS()
class GDP_CAPSTONE_TESTING_API ALightSwitch : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALightSwitch();
	
	//Add a pointlight Component
	UPROPERTY(VisibleAnywhere, Category= "SwitchComponent")
	class UPointLightComponent* PointLight1;
	
	// Sphere Collider for Overlaps
	UPROPERTY(VisibleAnywhere, Category= "SwitchComponent")
	class USphereComponent* Sphere1;
	
	// On Overlap Function
	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	// End Overlap Function
	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
	// Function for toggling light
	UFUNCTION()
	void ToggleLight();
	
	// Define Intensity
	UPROPERTY(VisibleAnywhere, Category= "SwitchVariables")
	float DesiredIntensity;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
