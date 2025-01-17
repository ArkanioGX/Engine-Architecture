#pragma once
#include <vector>
#include <SFML/Graphics/Transform.hpp>
#include <Engine/gameplay/components/Component.hpp>
#include <memory>


class PhysicsComponent : public Component {
public:

	PhysicsComponent() = delete;
	PhysicsComponent(class Entity* ownerT);

};