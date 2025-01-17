#pragma once
#include <vector>
#include <SFML/Graphics/Transform.hpp>
#include <Engine/gameplay/components/Component.hpp>
#include <memory>

class TargetComponent : public Component {
public:

	TargetComponent() = delete;
	TargetComponent(class Entity* ownerT);

	void begin() override;
	void update(float) override;
};