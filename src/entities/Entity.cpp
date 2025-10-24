#include"Entity.h"

Entity::Entity(int id,const std::string& tag)
	:m_id(id)
	,m_tag(tag)
{

}

int Entity::id()const
{
	return m_id;
}
const std::string& Entity::tag()const
{
	return m_tag;
}
bool Entity::is_alive()const
{
	return alive;
}

void Entity::destroy()
{
	alive = false;
}


Entity::~Entity()
{

}