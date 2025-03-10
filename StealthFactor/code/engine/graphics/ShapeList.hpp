#pragma once

#include <string>
#include <vector>
namespace sf {
	class Shape;
}


class ShapeList
{
public:
	using Shapes = std::vector<sf::Shape*>;

	bool load(const std::string &name);

	const Shapes &getShapes() const;

private:
	Shapes shapes;
};