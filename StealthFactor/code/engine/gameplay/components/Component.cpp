#include "Component.hpp"
#include <iostream>
#include <engine/gameplay/Entity.hpp>


Component::Component(Entity* ownerT) :
	owner(ownerT)
{
	owner->addComponent(this);
	std::cout << "Component Created";
}


Component::~Component()
{
	owner->removeComponent(this);
	std::cout << "Component Destroyed";
}

void Component::begin()
{
}

void Component::update(float dt)
{
}
