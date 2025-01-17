#include "Component.hpp"
#include <iostream>
#include <engine/gameplay/Entity.hpp>

Component::Component(Entity* ownerT) :
	owner(ownerT),
	type(Gameplay)
{
	owner->addComponent(std::make_shared<Component>(ownerT));
	std::cout << "Component Created";
}




Component::~Component()
{
	owner->removeComponent(std::make_shared<Component>(owner));
	std::cout << "Component Destroyed";
}

void Component::begin()
{
}

void Component::update(float)
{
}
