
#include <vector>
#include <SFML/Graphics/Transform.hpp>
#include <memory>

class Entity;

class Component {

protected:
	Entity* owner;

public:

	Component() = delete;
	Component(Entity* ownerT);

	virtual ~Component();

	virtual void begin();
	virtual void update(float dt);
};