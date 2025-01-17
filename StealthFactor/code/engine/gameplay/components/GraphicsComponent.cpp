#include "GraphicsComponent.hpp"
#include <iostream>
#include <engine/gameplay/Entity.hpp>

GraphicsComponent::GraphicsComponent(Entity* ownerT) :Component(ownerT)
{
	type = ComponentType::Graphics;
}

void GraphicsComponent::draw()
{
}

