
#pragma once

#include<glm/glm.hpp>
#include<string>
#include "VertexShader.h"
#include "FragmentShader.h"
#include<memory>

class Shader {
public:
	size_t ID;
	VertexShader* vertexShader;
	FragmentShader* fragmentShader;
	Shader(const std::shared_ptr<VertexShader>& vertexShader, const std::shared_ptr<FragmentShader>& fragmentShader);
	~Shader();

	void activate();
	void setMat4(std::string name , glm::mat4 value);
	void setFloat(std::string name, float value);
	void setInt(std::string name, int value);
	void setVec3(std::string name, glm::vec3 value);
	size_t location(std::string name);
	void setBool(const std::string& name, bool value) const;
	
	static std::string loadShaderSrc(const std::string& fileName);
};