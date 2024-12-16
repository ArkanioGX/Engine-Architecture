#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

		class ShapeList;

		class GraphicsManager
		{
		public:
			GraphicsManager();
			~GraphicsManager();

			void update();

			void clear();
			void draw(const ShapeList &shapeList, const sf::Transform &transform);
			void display();

			bool hasFocus() const;

		private:
			sf::RenderWindow window;

			static const sf::Int16 WINDOW_WIDTH = 800;
			static const sf::Int16 WINDOW_HEIGHT = 600;
		};
