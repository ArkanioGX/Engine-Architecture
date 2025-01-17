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

	class TargetComponent* targetComponent;
};
