// Copyright Burnt Shrimp


#include "Actor/CaelEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystem/CaelAttributeSet.h"
#include "Components/SphereComponent.h"


ACaelEffectActor::ACaelEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(MeshComponent);
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	SphereComponent->SetupAttachment(GetRootComponent());
	
}

void ACaelEffectActor::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyState,
	bool bFromSweep, const FHitResult& SweepResult)
{
	//TODO: Change this to apply a gameplay effect!!
	if (IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(OtherActor))
	{
		const UCaelAttributeSet* CaelAttributeSet = Cast<UCaelAttributeSet>(ASCInterface->GetAbilitySystemComponent()->GetAttributeSet(UCaelAttributeSet::StaticClass()));
		UCaelAttributeSet* MutableCaelAttributeSet = const_cast<UCaelAttributeSet*>(CaelAttributeSet);
		MutableCaelAttributeSet->SetHealth(CaelAttributeSet->GetHealth() - 25.f);
		Destroy();
	}
}

void ACaelEffectActor::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}


void ACaelEffectActor::BeginPlay()
{
	Super::BeginPlay();
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ACaelEffectActor::OnOverlap);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ACaelEffectActor::EndOverlap);
}
