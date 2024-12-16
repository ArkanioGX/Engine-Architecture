#pragma once

#include <string>

class Engine
{
public:
	Engine();

	void loadConfiguration();

	void run();
	float getDeltaTime() const;

	void exit();

	static Engine *GetGame();

private:
	bool running;
	float deltaTime;

	// Configuration
	std::string startMap;

	static Engine *instance;
};
