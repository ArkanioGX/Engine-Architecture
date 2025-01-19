#include "PlayerComponent.hpp"
#include <ode/collision.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/gameplay/entities/Target.hpp>
#include <engine/input/InputManager.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/Engine.hpp>
#include <engine/gameplay/Entity.hpp>
#include <engine/gameplay/components/BoxPhysicsComponent.hpp>

PlayerComponent::PlayerComponent(Entity* ownerT):Component(ownerT)
{
}

void PlayerComponent::update(float dt)
{
	dt++;
	justMoved = false;
	auto position = owner->getPosition();
	float rotation = owner->getRotation();

	if (Engine::GetEngine()->GetInput()->isKeyJustPressed(sf::Keyboard::Left))
	{
		justMoved = true;
		position.x -= GameManager::CELL_SIZE;
		rotation = 180.f;
	}

	if (Engine::GetEngine()->GetInput()->isKeyJustPressed(sf::Keyboard::Right))
	{
		justMoved = true;
		position.x += GameManager::CELL_SIZE;
		rotation = 0.f;
	}

	if (Engine::GetEngine()->GetInput()->isKeyJustPressed(sf::Keyboard::Up))
	{
		justMoved = true;
		position.y -= GameManager::CELL_SIZE;
		rotation = -90.f;
	}

	if (Engine::GetEngine()->GetInput()->isKeyJustPressed(sf::Keyboard::Down))
	{
		justMoved = true;
		position.y += GameManager::CELL_SIZE;
		rotation = 90.f;
	}

	if (justMoved)
	{
		owner->setPosition(position);
		owner->setRotation(rotation);
	}

	auto collisions = Engine::GetEngine()->GetPhysics()->getCollisionsWith(owner->getComponent<BoxPhysicsComponent*>()->getGeomID());
	for (auto& geomId : collisions)
	{
		auto entity = reinterpret_cast<Entity*>(dGeomGetData(geomId));
		auto targetEntity = dynamic_cast<Target*>(entity);
		if (targetEntity)
		{
			Engine::GetEngine()->GetGame()->loadNextMap();
		}
	}
}

bool PlayerComponent::hasJustMoved() const
{
	return justMoved;
}
