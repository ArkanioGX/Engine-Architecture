
#include <vector>
#include <SFML/Graphics/Transform.hpp>
#include <memory>

class Entity;

class Component {

	Entity* owner;

public:

	Component() = delete;
	Component(Entity* ownerT);

	~Component();

	virtual void begin() = 0;
	virtual void update() = 0;
};