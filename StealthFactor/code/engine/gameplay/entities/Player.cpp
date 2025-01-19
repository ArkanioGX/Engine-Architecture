#include "engine/gameplay/entities/Player.hpp"
#include <engine/gameplay/components/PlayerComponent.hpp>
#include <engine/gameplay/components/ShapesGraphicsComponent.hpp>
#include <engine/gameplay/components/BoxPhysicsComponent.hpp>
#include <engine/Engine.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>




Player::Player()
{
	BehaviorComponent = std::make_shared<PlayerComponent>(this);
	addComponent(BehaviorComponent);
	drawComponent = std::make_shared<ShapesGraphicsComponent>(this,"Player");
	addComponent(drawComponent);
	boxComponent = std::make_shared<BoxPhysicsComponent>(this);
	addComponent(boxComponent);
	
}


