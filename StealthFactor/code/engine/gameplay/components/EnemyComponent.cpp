#include "EnemyComponent.hpp"
#include <iostream>
#include <sstream>
#include <pugixml/pugixml.hpp>
#include <engine/Engine.hpp>
#include <engine/gameplay/GameplayManager.hpp>
#include <engine/gameplay/components/PlayerComponent.hpp>
#include <engine/gameplay/Entity.hpp>

EnemyComponent::EnemyComponent(Entity* owner, const std::string& archetypeName):
	Component(owner)
{
	loadArchetype(archetypeName);
}

void EnemyComponent::update(float dt)
{
	dt++;
	Entity* player = Engine::GetEngine()->GetGame()->getPlayer();
	PlayerComponent* plComp = player->getComponent<PlayerComponent*>();
	if (plComp->hasJustMoved())
	{
		auto& playerPosition = player->getPosition();
		auto& myPosition = owner->getPosition();

		auto offset = myPosition - playerPosition;
		offset /= GameManager::CELL_SIZE;
		float distance2 = offset.x * offset.x + offset.y * offset.y;
		if (distance2 <= visionRadius * visionRadius)
		{
			if (shootDelayCounter < shootDelay)
			{
				++shootDelayCounter;
			}
			else
			{
				Engine::GetEngine()->GetGame()->gameOver();
			}
		}
		else
		{
			shootDelayCounter = 0;
		}
	}
}

void EnemyComponent::begin()
{
}

void EnemyComponent::loadArchetype(const std::string& archetypeName)
{
	std::stringstream filename;
	filename << "archetypes/" << archetypeName << ".xml";

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(filename.str().c_str());

	if (result)
	{
		assert(!doc.empty());
		auto xmlArchetype = doc.first_child();

		std::string shapeListName = xmlArchetype.child_value("shapelist");
		//assert( load(shapeListName));

		visionRadius = std::stof(xmlArchetype.child_value("vision_radius"));
		assert(visionRadius > 0.f);

		shootDelay = std::stoi(xmlArchetype.child_value("shoot_delay"));
		assert(shootDelay >= 0);
	}
	else
	{
		std::cerr << "Archetype [" << archetypeName << "] parsed with errors." << std::endl;
		std::cerr << "Error description: " << result.description() << std::endl;
		std::cerr << "Error offset: " << result.offset << std::endl;
	}
}


