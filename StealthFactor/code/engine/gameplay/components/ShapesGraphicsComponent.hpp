#pragma once
#include <vector>
#include <SFML/Graphics/Transform.hpp>
#include <Engine/gameplay/components/GraphicsComponent.hpp>
#include <engine/graphics/ShapeList.hpp>
#include <memory>

class ShapesGraphicsComponent : public GraphicsComponent {
public:

	ShapesGraphicsComponent() = delete;
	ShapesGraphicsComponent(class Entity* ownerT, const std::string& name = "");

	void draw() override;

	bool loadShapes(const std::string& name);

private:
	ShapeList shapeList;

};