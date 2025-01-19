#pragma once


#include <engine/gameplay/entities/Character.hpp>

class Enemy : public Character
{
public:
	Enemy(const std::string &archetypeName);

private:
	std::shared_ptr<class EnemyComponent> behaviorComponent;
	std::shared_ptr<class ShapesGraphicsComponent> drawComponent;
	std::shared_ptr<class BoxPhysicsComponent> boxComponent;
};
