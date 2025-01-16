#include "Character.hpp"

#include <engine/Engine.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>

Character::Character()
{
	collisionGeomId = dCreateBox(Engine::GetEngine()->GetPhysics()->getSpaceId(), 0.f, 0.f, 0.f);
	dGeomSetData(collisionGeomId, this);
}

Character::~Character()
{
	dGeomDestroy(collisionGeomId);
}

void Character::draw()
{
	Engine::GetEngine()->GetGraphic()->draw(shapeList, getTransform());
}

ShapeList* Character::getShapeList()
{
	return &shapeList;
}
