#include"TransformSystem.h"
#include <glm/gtc/matrix_transform.hpp>   
#include <glm/gtx/transform.hpp>           
#include <glm/gtx/euler_angles.hpp>        
#include <glm/gtc/type_ptr.hpp>     
void updateMatrix(const std::shared_ptr<Entity>& entity)
{
	glm::mat4& transformationMatrix = entity->Ctransform->transformationMatrix;
	transformationMatrix = glm::translate(glm::mat4(1.0f), entity->Ctransform->position);
	
	transformationMatrix = glm::rotate(transformationMatrix, glm::radians(entity->Ctransform->rotation.y), glm::vec3(0, 1, 0));
	transformationMatrix = glm::rotate(transformationMatrix, glm::radians(entity->Ctransform->rotation.z), glm::vec3(0, 0, 1));
	transformationMatrix = glm::rotate(transformationMatrix, glm::radians(entity->Ctransform->rotation.x), glm::vec3(1, 0, 0));

	transformationMatrix = glm::scale(transformationMatrix, glm::vec3(entity->Ctransform->scale, entity->Ctransform->scale, entity->Ctransform->scale));
}

void TransformSystem::setRotation( std::shared_ptr<Entity>& entity, glm::vec3 r)
{
	entity->Ctransform->rotation = r;
	updateMatrix(entity);
}
void TransformSystem::setY(const std::shared_ptr<Entity>& entity, float y)
{
	entity->Ctransform->position.y = y;
	updateMatrix(entity);
}
glm::vec3 TransformSystem::getForwardVector(const std::shared_ptr<Entity>& entity)  {
	glm::mat4 rotMat = glm::yawPitchRoll(
		glm::radians(entity->Ctransform->rotation.y),
		glm::radians(entity->Ctransform->rotation.x),
	    glm::radians(entity->Ctransform->rotation.z)
	);
	glm::vec3 r = glm::normalize(glm::vec3(rotMat * glm::vec4(-1, 0, 0, 0)));
	r.y = 0;
	return r; 
}

void TransformSystem::translate(const std::shared_ptr<Entity>& entity, const glm::vec3& t)
{
	entity->Ctransform->position += t;
	updateMatrix(entity);
}
void TransformSystem::rotate(const std::shared_ptr<Entity>& entity, const glm::vec3& r)
{
	entity->Ctransform->rotation +=r;
	updateMatrix(entity);
}