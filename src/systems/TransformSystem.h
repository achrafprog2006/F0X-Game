#pragma once

#include<memory>
#include<vector>
#include"../entities/Entity.h"
#include<glm/glm.hpp>


namespace TransformSystem
{

	void translate(const std::shared_ptr<Entity>& entity, const glm::vec3& t);
	void rotate(const std::shared_ptr<Entity>& entity, const glm::vec3& r);
	 glm::vec3 getForwardVector(const std::shared_ptr<Entity>& entity);
	 void setY(const std::shared_ptr<Entity>& entity, float y);

	 void setRotation( std::shared_ptr<Entity>& entity, glm::vec3 r);
}