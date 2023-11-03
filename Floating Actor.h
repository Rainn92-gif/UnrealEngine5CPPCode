#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "myActorClass.generated.h"

UCLASS()
class GDP_CAPSTONE_TESTING_API AmyActorClass : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AmyActorClass();

	// Define Static Mesh Component
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* FloatMesh;

	// Define Speed of Float
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "myActorClass")
	float FloatSpeed = 20.0f;

	// Define Rotation Speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "myActorClass")
	float RotationSpeed = 20.0f;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
