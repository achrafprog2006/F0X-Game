#include"EntityManager.h"

const std::shared_ptr<Entity> EntityManager::addEntity(const std::string& tag)
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>(num_entities, tag);
	m_entities.push_back(entity);
	num_entities++;
	return entity;
}
const std::vector<std::shared_ptr<Entity>>& EntityManager::getEntities()const
{
	return m_entities;
}
const std::shared_ptr<Entity>& EntityManager::getEntity(int id)const
{
	return m_entities[id];
}


void EntityManager::update()
{
	int i = 0;
	for (auto entity : m_entities)
	{
		if (entity->is_alive())
			m_entities[i++] = entity;
	}
	m_entities.resize(i);

	for (auto entity : to_add_entities)
	{
		m_entities.push_back(entity);
	}
	to_add_entities.clear();
}