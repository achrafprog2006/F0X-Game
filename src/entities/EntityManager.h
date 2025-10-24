#pragma once
#include"Entity.h"
#include<string>
#include<vector>
#include<memory>

class EntityManager
{
	int num_entities = 0;
	std::vector<std::shared_ptr<Entity>> m_entities;
	std::vector<std::shared_ptr<Entity>> to_add_entities;

public:
	EntityManager() = default;
	const std::shared_ptr<Entity> addEntity(const std::string& tag);
	const std::vector<std::shared_ptr<Entity>>& getEntities()const;
	const std::shared_ptr<Entity>& getEntity(int id)const;
	void update();

};