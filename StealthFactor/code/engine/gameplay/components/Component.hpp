#pragma once
#include <vector>
#include <SFML/Graphics/Transform.hpp>
#include <memory>



enum ComponentType
{
	Gameplay,
	Graphics,
	Physics
};

class Component {

protected:
	class Entity* owner;
	
	ComponentType type;

public:

	ComponentType getType() const { return type; }

	Component(class Entity* ownerP);
	Component() = delete;
	virtual ~Component();
	Component(const Component&) = delete;
	Component& operator=(const Component&) = delete;

	virtual void begin();
	virtual void update(float);

};