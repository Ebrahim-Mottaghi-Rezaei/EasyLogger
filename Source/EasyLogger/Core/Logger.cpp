// Copyright Ebrahim Mottaghi Rezaei [https://www.linkedin.com/in/ebrahim-mr/]. All Rights Reserved.

#include "Logger.h"
#include "Engine.h"

//Defining the EasyLogger category
DEFINE_LOG_CATEGORY( EasyLogger );

int ULogger::Counter = 0;
TMap<FString, int> ULogger::CachedLogs;
int ULogger::NextLogId = 0;

void ULogger::Log(const FString& Message, const ELogVerbosity::Type Verbosity, const EEasyLoggerType On, const float Duration, const int Key) {
	/*auto LogId = -1;
	if ( Key == 0 ) {
		const auto MapLogId = CachedLogs.Find( Message );
		if ( MapLogId == nullptr ) {
			LogId = NextLogId++;
			CachedLogs.Add( Message, LogId );
		} else {
			LogId = *MapLogId;
		}
	} else {
		LogId = Key;
	}*/
	//Switching based on the given verbosity 
	switch ( Verbosity ) {
		case ELogVerbosity::Error:
			//printing the log to the screen
			if ( GEngine && On != EEasyLoggerType::Console )
				GEngine->AddOnScreenDebugMessage( Key, Duration, FColor::Red, *Message );

		//(also)printing the log to the output
			if ( On != EEasyLoggerType::Screen ) UE_LOG( EasyLogger, Error, TEXT("%s"), *Message );
			break;
		case ELogVerbosity::Warning:
			//printing the log to the screen
			if ( GEngine && On != EEasyLoggerType::Console )
				GEngine->AddOnScreenDebugMessage( Key, Duration, FColor::Orange, *Message );

		//(also)printing the log to the output
			if ( On != EEasyLoggerType::Screen ) UE_LOG( EasyLogger, Warning, TEXT("%s"), *Message );
			break;
		case ELogVerbosity::Display:
			//printing the log to the screen
			if ( GEngine && On != EEasyLoggerType::Console )
				GEngine->AddOnScreenDebugMessage( Key, Duration, /*FColor::FromHex( "FFA651FF" )*/FColor::Cyan, *Message );

		//(also)printing the log to the output
			if ( On != EEasyLoggerType::Screen ) UE_LOG( EasyLogger, Display, TEXT("%s"), *Message );
			break;
		default: ;
	}
}

void ULogger::LogInfo(const UObject* Object, const FString& Message, const EEasyLoggerType On, const float Duration, const int Key) {
	const auto KeyId = GetKeyIdByObject( Key, Object );
	//Calling the Log function with provided parameters
	if ( Object ) {
		Log( FString::Printf( TEXT( "[%s] %s" ), *UKismetSystemLibrary::GetDisplayName( Object ), *Message ), ELogVerbosity::Display, On, Duration, KeyId );
	} else
		Log( *Message, ELogVerbosity::Display, On, Duration, Key );
}

void ULogger::LogWarning(const UObject* Object, const FString& Message, const EEasyLoggerType On, const float Duration, const int Key) {
	const auto KeyId = GetKeyIdByObject( Key, Object );
	//Calling the Log function with provided parameters
	if ( Object ) {
		Log( FString::Printf( TEXT( "[%s] %s" ), *UKismetSystemLibrary::GetDisplayName( Object ), *Message ), ELogVerbosity::Warning, On, Duration, KeyId );
	} else
		Log( *Message, ELogVerbosity::Warning, On, Duration, Key );
}

void ULogger::LogError(const UObject* Object, const FString& Message, const EEasyLoggerType On, const float Duration, const int Key) {
	const auto KeyId = GetKeyIdByObject( Key, Object );
	//Calling the Log function with provided parameters
	if ( Object ) {
		Log( FString::Printf( TEXT( "[%s] %s" ), *UKismetSystemLibrary::GetDisplayName( Object ), *Message ), ELogVerbosity::Error, On, Duration, KeyId );
	} else
		Log( *Message, ELogVerbosity::Display, On, Duration, Key );
}

void ULogger::LogCounter(const EEasyLoggerType On, const float Duration) {
	//Calling the Log function with provided parameters
	Log( FString::Printf( TEXT( "Counter: %d" ), Counter++ ), ELogVerbosity::Display, On, Duration );
}

int ULogger::GetKeyIdByObject(const int Key, const UObject* Object) {
	if ( Key != 0 )
		return Key;

	const auto ObjectName = GetNameSafe( Object );

	const auto FoundIdPtr = CachedLogs.Find( ObjectName );

	int GeneratedKey;
	if ( FoundIdPtr == nullptr ) {
		GeneratedKey = NextLogId++;
		CachedLogs.Add( ObjectName, GeneratedKey );
	} else {
		GeneratedKey = *FoundIdPtr;
	}
	return GeneratedKey;
}

int ULogger::GetCounter() {
	return Counter;
}

int ULogger::GetRandomKey() {
	return FMath::Rand();
}
