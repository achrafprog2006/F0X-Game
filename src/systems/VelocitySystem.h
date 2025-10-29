#pragma once


#include "../components/StaticMesh.hpp"
#include<memory>
#include<vector>
#include"../entities/Entity.h"
#include<glm/glm.hpp>

#include"TransformSystem.h"


namespace VelocitySystem
{
	void move(const std::shared_ptr<Entity>& entity , float deltaTime);
	void move(const std::vector< std::shared_ptr<Entity>>& entities , float deltaTime);
	void accelerate(const std::shared_ptr<Entity>& entity, const glm::vec3& dV);
	float  velocityPower(const std::shared_ptr<Entity>& entity);
}