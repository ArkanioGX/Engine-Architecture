#include "engine/gameplay/entities/Player.hpp"
#include <engine/gameplay/components/PlayerComponent.hpp>



Player::Player()
{
	BehaviorComponent = new PlayerComponent(this);
	//shapeList.load("player");

	//collisionGeomId = dCreateBox(Engine::GetEngine()->GetPhysics()->getSpaceId(), GameManager::CELL_SIZE * 0.9f, GameManager::CELL_SIZE * 0.9f, 1.f);
	//dGeomSetData(collisionGeomId, this);
}


