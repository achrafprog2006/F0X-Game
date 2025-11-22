#include"Scene1.h"

#include<iostream>
#include<glad/glad.h>
#include <algorithm>


#include"../systems/TransformSystem.h"
#include"../systems/VelocitySystem.h"
#include"../systems/RenderSystem.h"
#include"../systems/TerrainSystem.h"


#include"../utils/TerrainGenerator.hpp"

#include"../Managers/ShaderManager.hpp"
#include"../Managers/TextureManager.hpp"


glm::vec3 pos{ 0.0f };
glm::vec3 rot{ 0.0f };

Scene1::Scene1( std::shared_ptr<Screen>& scr)
{
	screen = scr;
	ShaderManager::init();
	camera = std::make_shared<Camera>(glm::vec3(0.0f,3.0f,10.0f), rot, screen->SC_width,screen->SC_height);
	entityManager = std::make_unique<EntityManager>();
}

Scene1::~Scene1()
{}

void Scene1::init()
{
	
	//for(int i=0;i<64;i++)entityManager->addEntity("obj");

	//----------elk--------------------
	auto elk = entityManager->addEntity("elk");
	elk->Cmodel = std::make_shared<Model>("../resources/elk/scene.gltf");
	elk->Cshader = ShaderManager::get("shader");

	elk->Ctransform = std::make_shared<Transform>(
		glm::vec3(0, 0, 0),
		glm::vec3(0, 0, 0),
		5
	);
	elk->Cvelocity = std::make_shared<Velocity>();
	/* //------------bear---------
	auto bear = entityManager->addEntity("bear");
	bear->Cmodel = std::make_shared<Model>("./game/resources/bear/scene.gltf");
	bear->Cshader = ShaderManager::get("shader");

	bear->Ctransform = std::make_shared<Transform>(
		glm::vec3(10, 0, 10),
		glm::vec3(0, 0, 0),
		5
	);
	bear->Cvelocity = std::make_shared<Velocity>();

	//------------cool_man---------
	auto cool_man = entityManager->addEntity("cool_man");
	cool_man->Cmodel = std::make_shared<Model>("./game/resources/cool_man/scene.gltf");
	cool_man->Cshader = ShaderManager::get("shader");

	cool_man->Ctransform = std::make_shared<Transform>(
		glm::vec3(10, 0, 30),
		glm::vec3(0, 0, 0),
		6
	);
	cool_man->Cvelocity = std::make_shared<Velocity>();
	
	*/
	
	//-----------terrain------------
	std::vector<float> vertices_texCoords;
	std::vector<unsigned int> indices;

	int size = 100;         
	float spacing = 5.0f; 

	auto terrain = entityManager->addEntity("terrain");
	terrain->Cterrain= std::make_shared<Terrain>();

	TerrainGenerator::generate(vertices_texCoords, indices, spacing, size, "../resources/black.png", terrain->Cterrain->heightData);
    std::cout<<vertices_texCoords.size()<<"\n";
	terrain->CstaticMesh = std::make_shared<StaticMesh> (
		vertices_texCoords,
		indices,
		TextureManager::get("../resources/grassy3.png")
	);
	terrain->Cshader = ShaderManager::get("shader");
	terrain->Ctransform = std::make_shared<Transform>(
		glm::vec3(0, 0, 0),
		glm::vec3(0, 0, 0),
		1
	);
	terrain->Cvelocity = std::make_shared<Velocity>();
	
}

void Scene1::upload_Shader_Data()
{
	float time=((screen->time() * 1.0f));
		auto shader = ShaderManager::get("shader");
		shader->activate();
		shader->setFloat("time",time);
		shader->setMat4("viewMat", camera->getViewMatrix());
		shader->setMat4("projectionMat", camera->getProjectionMatrix());
	
}



void Scene1::hundle_input()
{
	float speed = 0.1f;
	if (screen->inputManager->isKeyPressed(GLFW_KEY_A))
	{
		camera->translate(glm::vec3(-speed, 0, 0));
	}
	if (screen->inputManager->isKeyPressed(GLFW_KEY_D))
	{
		camera->translate(glm::vec3(speed, 0, 0));
	}
	if (screen->inputManager->isKeyPressed(GLFW_KEY_S))
	{
		camera->translate(glm::vec3(0,-speed, 0));
	}
	if (screen->inputManager->isKeyPressed(GLFW_KEY_W))
	{
		camera->translate(glm::vec3(0, speed, 0));
	}
	if (screen->inputManager->isKeyPressed(GLFW_KEY_UP))
	{
		camera->translate(glm::vec3( 0, 0 ,-speed));
	}
	if (screen->inputManager->isKeyPressed(GLFW_KEY_DOWN))
	{
		camera->translate(glm::vec3(0, 0, speed));
	}
	if (screen->inputManager->isKeyPressed(GLFW_KEY_J))
	{
		camera->rotate(glm::vec3(0, 0.4f, 0));
	}
	if (screen->inputManager->isKeyPressed(GLFW_KEY_L))
	{
		camera->rotate(glm::vec3(0,-0.4f, 0));
	}
	
	if (screen->inputManager->isKeyPressed(GLFW_KEY_I))
	{
		camera->rotate(glm::vec3(0.4f, 0, 0));
	}
	if (screen->inputManager->isKeyPressed(GLFW_KEY_K))
	{
		camera->rotate(glm::vec3(-0.4f, 0, 0));
	}

}


void Scene1::update()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	entityManager->update();
	VelocitySystem::move(entityManager->getEntities(),screen->delta_time);
	hundle_input();
	
	upload_Shader_Data();
	RenderSystem::render(entityManager->getEntities());
}

