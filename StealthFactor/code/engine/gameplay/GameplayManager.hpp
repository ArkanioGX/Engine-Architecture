#pragma once

#include <set>
#include <string>
#include <SFML/System/Vector2.hpp>

class Entity;

class Player;

class GameManager
{
public:
	void update();
	void draw();

	void gameOver();

	sf::Vector2f getViewCenter() const;

	void setNewMapToLoad(const std::string& mapName);
	void loadNextMap();

	const Player &getPlayer() const;

	static const float CELL_SIZE;

private:
	std::set<Entity *> entities;
	Player *playerEntity{};

	void loadMap(const std::string& mapName);

	

	// Map
	std::string newMapToLoad = "";

	std::string currentMapName;
	std::string nextMapName;
	int rows{ 0 };
	int columns{ 0 };

	bool preventMapCompletion{ false };
	bool newMapRequested{ false };
};
