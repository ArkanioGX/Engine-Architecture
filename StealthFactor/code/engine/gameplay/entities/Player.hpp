#pragma once

#include <engine/gameplay/entities/Character.hpp>

class Player : public Character
{
public:
	Player();

private:
	class PlayerComponent* BehaviorComponent;
};
