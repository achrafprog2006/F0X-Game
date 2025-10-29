#include "VelocitySystem.h"
#include<cmath>
#include<glm/gtc/matrix_transform.hpp>
#include<iostream>

float maxSpeed = 100;

void VelocitySystem::move(const std::shared_ptr<Entity>& entity,float deltaTime)
{
	TransformSystem::translate(entity, entity->Cvelocity->velocity * deltaTime);
}

void VelocitySystem::move(const std::vector< std::shared_ptr<Entity>>& entities ,float deltaTime)
{
	for (auto entity : entities)
	{
		move(entity,deltaTime);
	}
}

void  VelocitySystem::accelerate(const std::shared_ptr<Entity>& entity, const glm::vec3& dV)
{
	entity->Cvelocity->velocity += dV;
	if (velocityPower(entity) > maxSpeed)
		entity->Cvelocity->velocity *= maxSpeed / velocityPower(entity);
}
 float  VelocitySystem::velocityPower(const std::shared_ptr<Entity>& entity)
{
	 return std::sqrtf(std::powf(entity->Cvelocity->velocity.x, 2) + std::powf(entity->Cvelocity->velocity.z, 2));
	// return glm::length(entity->Cvelocity->velocity);
}

