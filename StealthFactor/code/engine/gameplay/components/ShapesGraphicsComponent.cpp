#include "GraphicsComponent.hpp"
#include <iostream>
#include <engine/gameplay/Entity.hpp>
#include "ShapesGraphicsComponent.hpp"
#include "engine/graphics/GraphicsManager.hpp"
#include <engine/gameplay/Entity.hpp>
#include "engine/engine.hpp"

ShapesGraphicsComponent::ShapesGraphicsComponent(Entity* ownerT, const std::string& name) :GraphicsComponent(ownerT)
{
	if (name.size() >= 1 )
	shapeList.load(name);
}

void ShapesGraphicsComponent::draw()
{
	Engine::GetEngine()->GetGraphic()->draw(shapeList, owner->getTransform());
}

bool ShapesGraphicsComponent::loadShapes(const std::string& name)
{
	return shapeList.load(name);
}
