#include "Component.hpp"
#include <iostream>
#include <engine/gameplay/Entity.hpp>

Component::Component(Entity* ownerT) :
	owner(ownerT),
	type(Gameplay)
{
	std::cout << "Component Created";
}




Component::~Component()
{
	std::cout << "Component Destroyed";
}

void Component::begin()
{
}

void Component::update(float)
{
}
