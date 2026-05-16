// GreeterActor.h

#pragma once

#include "TempoServiceProvider.h"
#include "TempoServer.h"

#include "CoreMinimal.h"

#include "GreeterActor.generated.h"

namespace Greeter
{
	class GreeterRequest;
	class GreeterResponse;
}

UCLASS(Blueprintable)
class GREETER_API AGreeterActor : public AActor, public ITempoServiceProvider
{
	GENERATED_BODY()

public:
	virtual void RegisterServices(FTempoServer& Server) override;

	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString ResponseMessage = TEXT("Hello from server!");

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FColor DebugSphereColor = FColor::Green;

private:
	void HandleGreeterRequest(const Greeter::GreeterRequest& Request, const TResponseDelegate<Greeter::GreeterResponse>& ResponseContinuation) const;
};
