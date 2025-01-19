#include "TargetComponent.hpp"
#include <iostream>
#include <engine/gameplay/Entity.hpp>
#include <ode/collision.h>
#include "BoxPhysicsComponent.hpp"


TargetComponent::TargetComponent(Entity* ownerT) :Component(ownerT)
{

}

void TargetComponent::begin()
{
}

void TargetComponent::update(float dt)
{
	dt++;
	//auto& position = owner->getPosition();
	//dGeomSetPosition(owner->getComponent<BoxPhysicsComponent*>()->getGeomID(), position.x, position.y, 0);
}
