#include "engine/Engine.hpp"

#include <cassert>
#include <iostream>
#include <sstream>
#include <pugixml/pugixml.hpp>
#include <SFML/System.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/input/InputManager.hpp>

Engine *Engine::instance = nullptr;

Engine::Engine() :
	physics(new PhysicsManager()),
	graphic(new GraphicsManager()),
	game(new GameManager()),
	input(new InputManager())
{
	if (instance != nullptr) {
		delete this;
		return;
	}
	instance = this;
}

void Engine::loadConfiguration()
{
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("configuration.xml");

	if (result)
	{
		assert(!doc.empty());
		auto configuration = doc.first_child();
		startMap = configuration.child_value("start_map");
	}
	else
	{
		std::cerr << "Configuration parsed with errors." << std::endl;
		std::cerr << "Error description: " << result.description() << std::endl;
		std::cerr << "Error offset: " << result.offset << std::endl;
	}



}

void Engine::run()
{
	running = true;

	game->setNewMapToLoad(startMap);

	sf::Clock clock;
	while (running)
	{
		deltaTime = clock.restart().asSeconds();

		physics->update();
		game->update();
		graphic->update();

		graphic->clear();

		game->draw();

		graphic->display();
	}
}

float Engine::getDeltaTime() const
{
	return deltaTime;
}

void Engine::exit()
{
	running = false;
}

Engine* Engine::GetEngine()
{
	return instance;
}
