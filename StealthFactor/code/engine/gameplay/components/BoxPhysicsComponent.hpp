#pragma once
#include <vector>
#include <ode/collision.h>
#include <SFML/Graphics/Transform.hpp>
#include <Engine/gameplay/components/PhysicsComponent.hpp>
#include <memory>


class BoxPhysicsComponent : public PhysicsComponent {
public:

	BoxPhysicsComponent() = delete;
	BoxPhysicsComponent(class Entity* ownerT);

	~BoxPhysicsComponent();

	enum Moveability {
		Static,
		Moveable
	};

	Moveability moveability;

	

	void update(float dt) override;

	dGeomID getGeomID();

private:
	dGeomID collisionGeomId;
};