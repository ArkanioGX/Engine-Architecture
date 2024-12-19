#include "Component.hpp"
#include <iostream>
#include <engine/gameplay/Entity.hpp>


Component::Component(Entity* ownerT) :
	owner(ownerT)
{
	std::cout << "Component Created";
}


Component::~Component()
{
	std::cout << "Component Destroyed";
}
