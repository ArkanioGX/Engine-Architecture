#pragma once

#include <vector>
#include <SFML/Graphics/Transform.hpp>
#include <memory>
#include <iostream>

class Entity
{
public:
	virtual ~Entity() = default;

	virtual void update(float dt);
	virtual void draw() = 0;

	const sf::Vector2f &getPosition() const;
	void setPosition(const sf::Vector2f &newPosition);

	float getRotation() const;
	void setRotation(float newRotation);

	const sf::Transform &getTransform() const;

	void addComponent(class Component* cp);
	void removeComponent(class Component* cp);

protected:
	sf::Vector2f _position{};
	float _rotation{ 0.f };
	sf::Transform _transform;

	std::vector<std::shared_ptr<class Component>> components;

	void updateTransform();
};
