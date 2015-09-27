#pragma once
#include "logger.h"
class coloredLogger :
	public logger
{
public:
	void logInfo(std::string message) override
	{
		
	};
	void logWarning(std::string message) override
	{

	};
	void logError(std::string message) override
	{

	};

	coloredLogger()
	{
	}

	~coloredLogger()
	{
	}
};

