#include "TargetComponent.hpp"
#include <iostream>
#include <engine/gameplay/Entity.hpp>


TargetComponent::TargetComponent(Entity* ownerT) :Component(ownerT)
{

}

void TargetComponent::begin()
{
}

void TargetComponent::update(float dt)
{
	dt++;
}
