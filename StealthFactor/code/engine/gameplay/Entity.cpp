#include "Entity.hpp"
#include <engine/gameplay/components/GraphicsComponent.hpp>
#include <engine/gameplay/components/PhysicsComponent.hpp>


void Entity::update(float dt)
{
	for (auto component : components) {
		component->update(dt);
	}
}

void Entity::draw()
{
	for (auto component : graphicsComponents) {
		component->draw();
	}
}

const sf::Vector2f & Entity::getPosition() const
{
	return _position;
}

void Entity::setPosition(const sf::Vector2f &newPosition)
{
	_position = newPosition;
	updateTransform();
}

float Entity::getRotation() const
{
	return _rotation;
}

void Entity::setRotation(float newRotation)
{
	_rotation = newRotation;
	updateTransform();
}

const sf::Transform & Entity::getTransform() const
{
	return _transform;
}

void Entity::addComponent(std::shared_ptr<Component> cp)
{
	switch (cp.get()->getType()) {
	case ComponentType::Gameplay:
		components.push_back(cp);
		break;
	case ComponentType::Graphics:
		graphicsComponents.push_back(std::dynamic_pointer_cast<GraphicsComponent>(cp));
		break;
	case ComponentType::Physics:
		physicsComponents.push_back(std::dynamic_pointer_cast<PhysicsComponent>(cp));
		break;
	}
	
}

void Entity::removeComponent(std::shared_ptr<Component> cp)
{
	std::vector<std::shared_ptr<class Component>>::iterator componentFound;
	std::vector<std::shared_ptr<class GraphicsComponent>>::iterator gcomponentFound;
	std::vector<std::shared_ptr<class PhysicsComponent>>::iterator pcomponentFound;
	switch (cp.get()->getType()) {
	case ComponentType::Gameplay:
		componentFound = std::find(components.begin(), components.end(), cp);
		while (componentFound != components.end())
		{
			components.erase(componentFound);
		};
		break;
	case ComponentType::Graphics:
		gcomponentFound = std::find(graphicsComponents.begin(), graphicsComponents.end(), cp);
		while (gcomponentFound != graphicsComponents.end())
		{
			graphicsComponents.erase(gcomponentFound);
		};
		break;
	case ComponentType::Physics:
		pcomponentFound = std::find(physicsComponents.begin(), physicsComponents.end(), cp);
		while (pcomponentFound != physicsComponents.end())
		{
			physicsComponents.erase(pcomponentFound);
		};
		break;
	}	
}

void Entity::updateTransform()
{
	_transform = sf::Transform::Identity;
	_transform.translate(_position);
	_transform.rotate(_rotation);
}
