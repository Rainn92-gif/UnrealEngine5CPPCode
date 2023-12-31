#include "myActorClass.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// Sets default values
AmyActorClass::AmyActorClass()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create Static Mesh Component and Attach to Root
	FloatMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	FloatMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StaterContent/Shapes/Shape_Cube.Shape_Cube"));
	
	// If Mesh Asset id Found, Attach to root and set location to 0 in x, y and z.
	if (MeshAsset.Succeeded())
		FloatMesh->SetStaticMesh(MeshAsset.Object);
	FloatMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
}

// Called when the game starts or when spawned
void AmyActorClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AmyActorClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Define Actor Location and Rotation Variables
	FVector NewLocation = GetActorLocation();
	FRotator NewRotation = GetActorRotation();

	// Define RunningTime
	float RunningTime = GetGameTimeSinceCreation();

	// Add Sin Math to DeltaHeight
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) -FMath::Sin(RunningTime));

	// Add DeltaHeight to Z direction * floatSpeed
	NewLocation.Z += DeltaHeight * RotationSpeed;

	// Add Rotation to Yaw * Rotation Speed
	float DeltaRotation = DeltaTime * RotationSpeed;
	NewRotation.Yaw += DeltaRotation;

	// Set Actor Location and Rotation
	SetActorLocationAndRotation(NewLocation, NewRotation);
}
