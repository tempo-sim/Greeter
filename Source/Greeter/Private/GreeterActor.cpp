// GreeterActor.cpp

#include "GreeterActor.h"

#include "Greeter/GreeterService.grpc.pb.h"
#include "Greeter/GreeterService.pb.h"

using GreeterService = Greeter::GreeterService;
using GreeterServiceAsync = Greeter::GreeterService::AsyncService;
using GreeterRequest = Greeter::GreeterRequest;
using GreeterResponse = Greeter::GreeterResponse;

void AGreeterActor::RegisterScriptingServices(FTempoScriptingServer& ScriptingServer)
{
	ScriptingServer.RegisterService<GreeterService>(
		 SimpleRequestHandler(&GreeterServiceAsync::RequestGreet, &AGreeterActor::HandleGreeterRequest)
	 );
}

void AGreeterActor::BeginPlay()
{
	Super::BeginPlay();

	FTempoScriptingServer::Get().ActivateService<GreeterService>(this);
}

void AGreeterActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	FTempoScriptingServer::Get().DeactivateService<GreeterService>();
}

void AGreeterActor::HandleGreeterRequest(const GreeterRequest& Request, const TResponseDelegate<GreeterResponse>& ResponseContinuation) const
{
	const FString RequestMessage(UTF8_TO_TCHAR(Request.message().c_str()));
	UE_LOG(LogTemp, Warning, TEXT("GreeterActor received message: %s"), *RequestMessage);
	DrawDebugSphere(GetWorld(), GetActorLocation(), 50.0, 10, DebugSphereColor, false, 10.0, 0, 10.0);
	GreeterResponse Response;
	Response.set_message(std::string(TCHAR_TO_UTF8(*ResponseMessage)));
	ResponseContinuation.ExecuteIfBound(Response, grpc::Status_OK);
}
