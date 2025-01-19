#pragma once

#include <vector>
#include <SFML/Graphics/Transform.hpp>
#include <memory>
#include <iostream>
#include <engine/gameplay/components/Component.hpp>
#include <engine/gameplay/components/GraphicsComponent.hpp>
#include <engine/gameplay/components/PhysicsComponent.hpp>

class Entity
{
public:
	virtual ~Entity() = default;

	virtual void update(float dt);
	void draw();

	const sf::Vector2f &getPosition() const;
	void setPosition(const sf::Vector2f &newPosition);

	float getRotation() const;
	void setRotation(float newRotation);

	const sf::Transform &getTransform() const;

	void addComponent(std::shared_ptr<Component> cp);
	void removeComponent(std::shared_ptr<Component>cp);

	template <typename CompType>
	CompType getComponent();

protected:
	sf::Vector2f _position{};
	float _rotation{ 0.f };
	sf::Transform _transform;

	std::vector<std::shared_ptr<Component>> components;
	std::vector<std::shared_ptr<GraphicsComponent>> graphicsComponents;
	std::vector<std::shared_ptr<PhysicsComponent>> physicsComponents;

	void updateTransform();
};

template<typename CompType>
inline CompType Entity::getComponent()
{
	for (std::shared_ptr<Component> currComp : components)
	{
		CompType currentEntry = dynamic_cast<CompType>(currComp.get());
		if (currentEntry != nullptr)
		{
			return currentEntry;
		}
	}
	return nullptr;
}
