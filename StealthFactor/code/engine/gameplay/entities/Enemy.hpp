#pragma once


#include <engine/gameplay/entities/Character.hpp>

class Enemy : public Character
{
public:
	Enemy(const std::string &archetypeName);

private:
	class EnemyComponent* behaviorComponent;

};
