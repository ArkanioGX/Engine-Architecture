#include "Enemy.hpp"
#include <engine/gameplay/components/EnemyComponent.hpp>
#include <engine/gameplay/components/ShapesGraphicsComponent.hpp>
#include <engine/gameplay/components/BoxPhysicsComponent.hpp>


Enemy::Enemy(const std::string &archetypeName)
{
	drawComponent = std::make_shared<ShapesGraphicsComponent>(this);
	addComponent(drawComponent);
	behaviorComponent = std::make_shared<EnemyComponent>(this, archetypeName);
	addComponent(behaviorComponent);
	boxComponent = std::make_shared<BoxPhysicsComponent>(this);
	addComponent(boxComponent);
}


