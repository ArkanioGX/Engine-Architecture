#include "GraphicsComponent.hpp"
#include <iostream>
#include <engine/gameplay/Entity.hpp>
#include "BoxPhysicsComponent.hpp"
#include <engine/Engine.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/gameplay/GameplayManager.hpp>

BoxPhysicsComponent::BoxPhysicsComponent(Entity* ownerT) :PhysicsComponent(ownerT),
moveability(Moveable)

{
	collisionGeomId = dCreateBox(Engine::GetEngine()->GetPhysics()->getSpaceId(), GameManager::CELL_SIZE * 0.9f, GameManager::CELL_SIZE * 0.9f, 1.f);
	dGeomSetData(collisionGeomId, ownerT);
}

BoxPhysicsComponent::~BoxPhysicsComponent()
{
	dGeomDestroy(collisionGeomId);
}

void BoxPhysicsComponent::update(float dt)
{
	dt++;
	if (moveability == Moveable) {
		dGeomSetPosition(collisionGeomId, owner->getPosition().x, owner->getPosition().y, 0);
	}
}

dGeomID BoxPhysicsComponent::getGeomID()
{
	return collisionGeomId;
}
