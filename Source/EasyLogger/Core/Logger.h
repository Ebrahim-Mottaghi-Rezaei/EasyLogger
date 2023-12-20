// Copyright Ebrahim Mottaghi Rezaei [https://www.linkedin.com/in/ebrahim-mr/]. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Logger.generated.h"
DECLARE_LOG_CATEGORY_EXTERN( EasyLogger , All , All );

UENUM( BlueprintType , Category="Easy Logger" )
enum class EEasyLoggerType :uint8 {
	Screen  = 0 UMETA( DisplayName = "Screen" ),
	Console = 1 UMETA( DisplayName = "Console" ),
	Both    = 2 UMETA( DisplayName = "Both" ),
};

UCLASS()
class EASYLOGGER_API ULogger : public UBlueprintFunctionLibrary {
	GENERATED_BODY()
	static void Log(const FString& Message, const ELogVerbosity::Type Verbosity, const EEasyLoggerType On, const float Duration);

public:
	UFUNCTION( BlueprintCallable , Category = "Easy Logger" )
	static void LogInfo(UObject* Object, const FString& Message, const EEasyLoggerType On = EEasyLoggerType::Screen, const float Duration = 3.0f);

	UFUNCTION( BlueprintCallable , Category = "Easy Logger" )
	static void LogWarning(UObject* Object, const FString& Message, const EEasyLoggerType On = EEasyLoggerType::Both, const float Duration = 5.0f);

	UFUNCTION( BlueprintCallable , Category = "Easy Logger" )
	static void LogError(UObject* Object, const FString& Message, const EEasyLoggerType On = EEasyLoggerType::Both, const float Duration = 10.0f);

	UFUNCTION( BlueprintCallable , Category = "Easy Logger" )
	static void LogInfoAnonymously(const FString& Message, const EEasyLoggerType On = EEasyLoggerType::Screen, const float Duration = 3.0f);

	UFUNCTION( BlueprintCallable , Category = "Easy Logger" )
	static void LogWarningAnonymously(const FString& Message, const EEasyLoggerType On = EEasyLoggerType::Both, const float Duration = 5.0f);

	UFUNCTION( BlueprintCallable , Category = "Easy Logger" )
	static void LogErrorAnonymously(const FString& Message, const EEasyLoggerType On = EEasyLoggerType::Both, const float Duration = 10.0f);
};
