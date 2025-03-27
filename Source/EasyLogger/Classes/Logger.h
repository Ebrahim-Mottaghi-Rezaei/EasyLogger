// Copyright Ebrahim Mottaghi Rezaei [https://www.linkedin.com/in/ebrahim-mr/]. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Logger.generated.h"
DECLARE_LOG_CATEGORY_EXTERN( EasyLogger, All, All );

UENUM( BlueprintType, Category="Easy Logger" )
enum class EEasyLoggerType :uint8 {
	Screen = 0 UMETA( DisplayName = "Screen" ),
	Console = 1 UMETA( DisplayName = "Console" ),
	Both = 2 UMETA( DisplayName = "Screen and Console" ),
};

UCLASS()
class EASYLOGGER_API ULogger : public UBlueprintFunctionLibrary {
	GENERATED_BODY()
	static void Log(const FString& Message, const ELogVerbosity::Type Verbosity, const EEasyLoggerType On, const float Duration, int Key = 0);

public:
	//Logging info message with Object's DisplayName to the desired channel. Screen, Console or both
	UFUNCTION( BlueprintCallable, Category = "Easy Logger", meta=(DevelopmentOnly) )
	static void LogInfo(const UObject* Object, const FString& Message, const EEasyLoggerType On = EEasyLoggerType::Both, const float Duration = 3.0f, const int Key = 0);

	//Logging warning message with Object's DisplayName to the desired channel. Screen, Console or both
	UFUNCTION( BlueprintCallable, Category = "Easy Logger", meta=(DevelopmentOnly) )
	static void LogWarning(const UObject* Object, const FString& Message, const EEasyLoggerType On = EEasyLoggerType::Both, const float Duration = 5.0f, const int Key = 0);

	//Logging error message with Object's DisplayName to the desired channel. Screen, Console or both
	UFUNCTION( BlueprintCallable, Category = "Easy Logger", meta=(DevelopmentOnly) )
	static void LogError(const UObject* Object, const FString& Message, const EEasyLoggerType On = EEasyLoggerType::Both, const float Duration = 10.0f, const int Key = 0);

	UFUNCTION( BlueprintCallable, Category = "Easy Logger", meta=(DevelopmentOnly) )
	static void LogCounter(const EEasyLoggerType On = EEasyLoggerType::Both, const float Duration = 10.0f);

	UFUNCTION( BlueprintCallable, Category = "Easy Logger", meta=(DevelopmentOnly) )
	static int GetKeyIdByObject(const int Key, const UObject* Object);

	static int GetCounter();

	static int GetRandomKey();

private:
	static int Counter;
	static TMap<FString, int> CachedLogs;
	static int NextLogId;
};
