#pragma once

#include <ode/collision.h>
#include <engine/graphics/ShapeList.hpp>
#include <engine/gameplay/Entity.hpp>

class Target : public Entity
{
public:
	Target();
	~Target();

private:

	std::shared_ptr<class ShapesGraphicsComponent> drawComponent;
	std::shared_ptr<class TargetComponent>targetComponent;
	std::shared_ptr<class BoxPhysicsComponent> boxComponent;
	
};
