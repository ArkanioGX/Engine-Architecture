#pragma once

#include <engine/gameplay/entities/Character.hpp>

class Player : public Character
{
public:
	Player();

private:
	std::shared_ptr<class PlayerComponent> BehaviorComponent;
	std::shared_ptr<class ShapesGraphicsComponent> drawComponent;
	std::shared_ptr<class BoxPhysicsComponent> boxComponent;
};
