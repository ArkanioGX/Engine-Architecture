#include "Entity.hpp"
#include <engine/gameplay/components/Component.hpp>

void Entity::update(float dt)
{
	for (int i = 0; i < components.size(); i++) {
		components[i].get()->update(dt);
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

void Entity::addComponent(Component* cp)
{
	components.push_back(std::make_shared<Component>(cp));
}

void Entity::removeComponent(Component* cp)
{
	std::vector<std::shared_ptr<class Component>>::iterator componentFound = components.end();
	for (int i = 0; i < components.size(); i++) {
		if (cp == components[i].get()) {
			componentFound = components.begin() + i;
			break;
		}
	}
	if (componentFound == components.end()) return;
	components.erase(componentFound);
}

void Entity::updateTransform()
{
	_transform = sf::Transform::Identity;
	_transform.translate(_position);
	_transform.rotate(_rotation);
}
