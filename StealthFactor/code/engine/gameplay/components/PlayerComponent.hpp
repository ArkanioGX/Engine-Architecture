#pragma once
#include <engine/gameplay/components/Component.hpp>

class PlayerComponent : public Component
{
public:
	PlayerComponent(Entity* ownerT);

	void update(float) override;

	bool hasJustMoved() const;

private:
	bool justMoved{ false };
};

