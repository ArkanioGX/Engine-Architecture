#include "engine/input/InputManager.hpp"

#include <iterator>
#include <engine/graphics/GraphicsManager.hpp>
#include <engine/Engine.hpp>

bool InputManager::isKeyPressed(sf::Keyboard::Key key) const
{
	if (!Engine::GetEngine()->GetGraphic()->hasFocus())
		return false;

	return sf::Keyboard::isKeyPressed(key);
}

bool InputManager::isKeyJustPressed(sf::Keyboard::Key key) const
{
	if (!Engine::GetEngine()->GetGraphic()->hasFocus())
		return false;

	return justPressedKeys.find(key) != std::end(justPressedKeys);
}

bool InputManager::isKeyJustReleased(sf::Keyboard::Key key) const
{
	if (!Engine::GetEngine()->GetGraphic()->hasFocus())
		return false;

	return justReleasedKeys.find(key) != std::end(justReleasedKeys);
}

void InputManager::clear()
{
	justPressedKeys.clear();
	justReleasedKeys.clear();
}

void InputManager::onKeyPressed(const sf::Event::KeyEvent &event)
{
	justPressedKeys.insert(event.code);
}

void InputManager::onKeyReleased(const sf::Event::KeyEvent &event)
{
	justReleasedKeys.insert(event.code);
}

