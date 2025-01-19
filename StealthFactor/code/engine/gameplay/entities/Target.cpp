#include "Target.hpp"

#include <engine/Engine.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/gameplay/components/TargetComponent.hpp>
#include <engine/gameplay/components/ShapesGraphicsComponent.hpp>
#include <engine/gameplay/components/BoxPhysicsComponent.hpp>


Target::Target()
{
	boxComponent = std::make_shared<BoxPhysicsComponent>(this);
	addComponent(boxComponent);
	targetComponent = std::make_shared<TargetComponent>(this);
	addComponent(targetComponent);
	drawComponent = std::make_shared<ShapesGraphicsComponent>(this,"target");
	addComponent(drawComponent);
	
}

Target::~Target()
{
	
}

