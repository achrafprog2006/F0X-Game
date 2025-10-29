#pragma once
#include<string>
#include<memory>
#include"../components/StaticMesh.hpp"
#include"../components/Transform.hpp"
#include"../components/Velocity.hpp"
#include"../components/Terrain.hpp"
#include"../shaders/Shader.h"

class Entity
{
	int m_id;
	std::string m_tag;
	bool alive = true;

public:
	Entity(int id, const std::string& tag);
	~Entity();

	//std::shared_ptr<Model> Cmodel;
	std::shared_ptr<Shader> Cshader;
	std::shared_ptr<StaticMesh> CstaticMesh;

	std::shared_ptr<Transform> Ctransform;
	std::shared_ptr<Velocity> Cvelocity;
	//std::shared_ptr<Model> Cmodel;

	std::shared_ptr<Terrain> Cterrain;

	int id()const;
	bool is_alive()const;
	const std::string& tag()const;

	void destroy();

};