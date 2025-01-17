#pragma once
#include <vector>
#include <SFML/Graphics/Transform.hpp>
#include <Engine/gameplay/components/Component.hpp>
#include <memory>

class GraphicsComponent : public Component {
public:

	GraphicsComponent() = delete;
	GraphicsComponent(class Entity* ownerT);

	virtual void draw();
};