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

	static Engine *GetEngine();

	class PhysicsManager* GetPhysics() { return physics; };
	class GraphicsManager* GetGraphic() { return graphic; };
	class InputManager* GetInput() { return input; };
	class GameManager* GetGame() {return game;};

private:
	bool running;
	float deltaTime;

	// Configuration
	std::string startMap;

	class PhysicsManager* physics;
	class GraphicsManager* graphic;
	class InputManager* input;
	class GameManager* game;

	static Engine *instance;
};
