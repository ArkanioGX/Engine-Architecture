#include "engine/gameplay/entities/Player.hpp"

#include <ode/collision.h>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/gameplay/entities/Target.hpp>
#include <engine/input/InputManager.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/Engine.hpp>

Player::Player()
{
	shapeList.load("player");

	collisionGeomId = dCreateBox(Engine::GetEngine()->GetPhysics()->getSpaceId(), GameManager::CELL_SIZE * 0.9f, GameManager::CELL_SIZE * 0.9f, 1.f);
	dGeomSetData(collisionGeomId, this);
}

void Player::update()
{
	justMoved = false;
	auto position = getPosition();
	float rotation = getRotation();

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
		setPosition(position);
		setRotation(rotation);

		dGeomSetPosition(collisionGeomId, position.x, position.y, 0);
	}

	auto collisions = Engine::GetEngine()->GetPhysics()->getCollisionsWith(collisionGeomId);
	for (auto &geomId : collisions)
	{
		auto entity = reinterpret_cast<Entity *>(dGeomGetData(geomId));
		auto targetEntity = dynamic_cast<Target *>(entity);
		if (targetEntity)
		{
			Engine::GetEngine()->GetGame()->loadNextMap();
		}
	}
}

bool Player::hasJustMoved() const
{
	return justMoved;
}
