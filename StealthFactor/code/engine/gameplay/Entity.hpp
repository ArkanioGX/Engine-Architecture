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
	virtual void draw();

	const sf::Vector2f &getPosition() const;
	void setPosition(const sf::Vector2f &newPosition);

	float getRotation() const;
	void setRotation(float newRotation);

	const sf::Transform &getTransform() const;

	void addComponent(std::shared_ptr<class Component> cp);
	void removeComponent(std::shared_ptr<class Component> cp);

	template <typename CompType>
	CompType getComponent();

protected:
	sf::Vector2f _position{};
	float _rotation{ 0.f };
	sf::Transform _transform;

	std::vector<std::shared_ptr<class Component>> components;
	std::vector<std::shared_ptr<class GraphicsComponent>> graphicsComponents;
	std::vector<std::shared_ptr<class PhysicsComponent>> physicsComponents;

	void updateTransform();
};

template<typename CompType>
inline CompType Entity::getComponent()
{
	for (std::shared_ptr<class Component> currComp : components)
	{
		CompType currentEntry = dynamic_cast<CompType>(currComp.get());
		if (currentEntry != nullptr)
		{
			return currentEntry;
		}
	}
	return nullptr;
}
