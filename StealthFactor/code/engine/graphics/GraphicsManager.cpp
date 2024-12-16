#include "engine/graphics/GraphicsManager.hpp"

#include <cassert>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/Event.hpp>
#include <engine/input/InputManager.hpp>
#include <engine/graphics/ShapeList.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/Engine.hpp>

GraphicsManager::GraphicsManager()
{
	window.create(sf::VideoMode{ (unsigned int)WINDOW_WIDTH, (unsigned int)WINDOW_HEIGHT }, "Stealth Factor");

	window.setVerticalSyncEnabled(true);

	sf::View view(sf::Vector2f{ 0.f, 0.f }, sf::Vector2f{ (float)WINDOW_WIDTH, (float)WINDOW_HEIGHT });
	window.setView(view);
}

GraphicsManager::~GraphicsManager()
{
	window.close();
}

void GraphicsManager::update()
{
	Engine::GetEngine()->GetInput()->clear();

	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			Engine::GetEngine()->exit();
			break;

		case sf::Event::KeyPressed:
			Engine::GetEngine()->GetInput()->onKeyPressed(event.key);
			break;

		case sf::Event::KeyReleased:
			Engine::GetEngine()->GetInput()->onKeyReleased(event.key);
			break;

		default:
			break;
		}
	}
}

void GraphicsManager::clear()
{
	window.clear(sf::Color::Black);

	sf::View view{ Engine::GetEngine()->GetGame()->getViewCenter(), sf::Vector2f{(float)WINDOW_WIDTH, (float)WINDOW_HEIGHT} };
	window.setView(view);
}

void GraphicsManager::draw(const ShapeList &shapeList, const sf::Transform &transform)
{
	sf::RenderStates renderStates{ transform };
	for (auto shape : shapeList.getShapes())
	{
		window.draw(*shape, renderStates);
	}
}

void GraphicsManager::display()
{
	window.display();
}

bool GraphicsManager::hasFocus() const
{
	return window.hasFocus();
}
