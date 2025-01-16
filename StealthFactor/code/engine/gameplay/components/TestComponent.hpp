#pragma once
#include <engine/gameplay/components/Component.hpp>
class TestComponent : public Component
{
public:
	TestComponent() = delete;
	TestComponent(Entity* ownerT);
	~TestComponent();

	void update(float dt) override;
	void begin() override;
};

