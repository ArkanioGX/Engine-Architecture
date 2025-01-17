#include "Target.hpp"

#include <engine/Engine.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/physics/PhysicsManager.hpp>
#include <engine/gameplay/components/TargetComponent.hpp>


Target::Target()
{
	targetComponent = new TargetComponent(this);

	//shapeList.load("target");

	//collisionGeomId = dCreateBox(Engine::GetEngine()->GetPhysics()->getSpaceId(), GameManager::CELL_SIZE * 0.9f, GameManager::CELL_SIZE * 0.9f, 1.f);
	//dGeomSetData(collisionGeomId, this);
}

Target::~Target()
{
	//dGeomDestroy(collisionGeomId);
}

/*void Target::update()
{
	//auto &position = getPosition();
	//dGeomSetPosition(collisionGeomId, position.x, position.y, 0);
}

void Target::draw()
{
	//Engine::GetEngine()->GetGraphic()->draw(shapeList, getTransform());
}*/
