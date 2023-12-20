// Copyright Ebrahim Mottaghi Rezaei [https://www.linkedin.com/in/ebrahim-mr/]. All Rights Reserved.

#include "Logger.h"
#include "Engine.h"
DEFINE_LOG_CATEGORY( EasyLogger );


void ULogger::Log(const FString& Message, const ELogVerbosity::Type Verbosity, const EEasyLoggerType On, const float Duration) {
	switch ( Verbosity ) {
		case ELogVerbosity::Error:
			if ( On != EEasyLoggerType::Console && GEngine )
				GEngine->AddOnScreenDebugMessage( -1 , Duration , FColor::Red , *Message );

			UE_LOG( EasyLogger , Error , TEXT("%s") , *Message );
			break;
		case ELogVerbosity::Warning:
			if ( On != EEasyLoggerType::Console && GEngine )
				GEngine->AddOnScreenDebugMessage( -1 , Duration , FColor::Orange , *Message );

			UE_LOG( EasyLogger , Warning , TEXT("%s") , *Message );
			break;
		case ELogVerbosity::Display:
			if ( On != EEasyLoggerType::Console && GEngine )
				GEngine->AddOnScreenDebugMessage( -1 , Duration , FColor::White , *Message );

			UE_LOG( EasyLogger , Display , TEXT("%s") , *Message );
			break;
		default: ;
	}
}


void ULogger::LogInfo(UObject* Object, const FString& Message, const EEasyLoggerType On, const float Duration) {
	LogInfoAnonymously( FString::Printf( TEXT( "[%s] %s" ) , *GetNameSafe( Object ) , *Message ) , On , Duration );
}


void ULogger::LogWarning(UObject* Object, const FString& Message, const EEasyLoggerType On, const float Duration) {
	LogWarningAnonymously( FString::Printf( TEXT( "[%s] %s" ) , *GetNameSafe( Object ) , *Message ) , On , Duration );
}


void ULogger::LogError(UObject* Object, const FString& Message, const EEasyLoggerType On, const float Duration) {
	LogErrorAnonymously( FString::Printf( TEXT( "[%s] %s" ) , *GetNameSafe( Object ) , *Message ) , On , Duration );
}


void ULogger::LogInfoAnonymously(const FString& Message, const EEasyLoggerType On, const float Duration) {
	Log( Message , ELogVerbosity::Type::Display , On , Duration );
}


void ULogger::LogWarningAnonymously(const FString& Message, const EEasyLoggerType On, const float Duration) {
	Log( Message , ELogVerbosity::Type::Warning , On , Duration );
}


void ULogger::LogErrorAnonymously(const FString& Message, const EEasyLoggerType On, const float Duration) {
	Log( Message , ELogVerbosity::Type::Error , On , Duration );
}
