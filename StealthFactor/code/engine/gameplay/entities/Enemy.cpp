#include "Enemy.hpp"
#include <engine/gameplay/components/EnemyComponent.hpp>


Enemy::Enemy(const std::string &archetypeName)
{
	behaviorComponent = new EnemyComponent(this, archetypeName);
}


