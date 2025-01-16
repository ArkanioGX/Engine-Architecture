#pragma once
#include <engine/gameplay/components/Component.hpp>
#include <string>

class EnemyComponent : public Component
{

public:
	EnemyComponent() = delete;
	EnemyComponent(Entity* owner, const std::string& archetypeName);

	void update(float dt) override;
	void begin() override;

	void loadArchetype(const std::string& archetypeName);

private:

	float visionRadius{ 0 };
	int shootDelay{ 0 };
	int shootDelayCounter{ 0 };
};

