#pragma once

#include <string>
#include <memory>


class Engine
{
private:
	bool running;
	float deltaTime;

	// Configuration
	std::string startMap;

	std::unique_ptr<class PhysicsManager> physics;
	std::unique_ptr<class GraphicsManager> graphic;
	std::unique_ptr<class InputManager> input;
	std::unique_ptr<class GameManager> game;

	static Engine* instance;

public:
	Engine();

	void loadConfiguration();

	void run();
	float getDeltaTime() const;

	void exit();

	static Engine *GetEngine();

	class PhysicsManager* GetPhysics() { return physics.get(); };
	class GraphicsManager* GetGraphic() { return graphic.get(); };
	class InputManager* GetInput() { return input.get(); };
	class GameManager* GetGame() {return game.get();};


};
