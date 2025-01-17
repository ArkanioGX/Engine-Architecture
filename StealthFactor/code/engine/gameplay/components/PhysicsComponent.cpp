#include "GraphicsComponent.hpp"
#include <iostream>
#include <engine/gameplay/Entity.hpp>
#include "PhysicsComponent.hpp"

PhysicsComponent::PhysicsComponent(Entity* ownerT) :Component(ownerT)

{
	type = ComponentType::Physics;
}
