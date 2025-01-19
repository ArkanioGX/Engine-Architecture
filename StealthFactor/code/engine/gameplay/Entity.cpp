#include "Entity.hpp"
#include <engine/gameplay/components/GraphicsComponent.hpp>
#include <engine/gameplay/components/PhysicsComponent.hpp>


void Entity::update(float dt)
{
	for (auto component : components) {
		component->update(dt);
	}
	for (auto component : physicsComponents) {
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

void Entity::addComponent(std::shared_ptr<Component> inCp)
{
	switch (inCp.get()->getType()) {
	case ComponentType::Gameplay:
		components.push_back(inCp);
		break;
	case ComponentType::Graphics:
		components.push_back(inCp);
		graphicsComponents.push_back(std::dynamic_pointer_cast<GraphicsComponent>(inCp));
		break;
	case ComponentType::Physics:
		components.push_back(inCp);
		physicsComponents.push_back(std::dynamic_pointer_cast<PhysicsComponent>(inCp));
		break;
	}
	
}

void Entity::removeComponent(std::shared_ptr<Component> inCp)
{
	std::vector<std::shared_ptr<Component>>::iterator componentFound;
	std::vector<std::shared_ptr<GraphicsComponent>>::iterator gcomponentFound;
	std::vector<std::shared_ptr<PhysicsComponent>>::iterator pcomponentFound;
	switch (inCp.get()->getType()) {
	case ComponentType::Gameplay:
		gcomponentFound = std::find(graphicsComponents.begin(), graphicsComponents.end(), inCp);
		while (gcomponentFound != graphicsComponents.end())
		{
			graphicsComponents.erase(gcomponentFound);
		};
		break;
	case ComponentType::Graphics:
		gcomponentFound = std::find(graphicsComponents.begin(), graphicsComponents.end(), inCp);
		while (gcomponentFound != graphicsComponents.end())
		{
			graphicsComponents.erase(gcomponentFound);
		};
		gcomponentFound = std::find(graphicsComponents.begin(), graphicsComponents.end(), inCp);
		while (gcomponentFound != graphicsComponents.end())
		{
			graphicsComponents.erase(gcomponentFound);
		};
		break;
	case ComponentType::Physics:
		gcomponentFound = std::find(graphicsComponents.begin(), graphicsComponents.end(), inCp);
		while (gcomponentFound != graphicsComponents.end())
		{
			graphicsComponents.erase(gcomponentFound);
		};
		pcomponentFound = std::find(physicsComponents.begin(), physicsComponents.end(), inCp);
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
