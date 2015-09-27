#pragma once
#include <string>

class logger
{
public:

	logger()
	{
	}

	~logger()
	{
	}

	virtual void logInfo(std::string message) =0;
	virtual void logWarning(std::string message) = 0;
	virtual void logError(std::string message) = 0;
};
