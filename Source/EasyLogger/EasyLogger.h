// Copyright Ebrahim Mottaghi Rezaei [https://www.linkedin.com/in/ebrahim-mr/]. All Rights Reserved. April 2024

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FEasyLoggerModule: public IModuleInterface {
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;

	virtual void ShutdownModule() override;
};
