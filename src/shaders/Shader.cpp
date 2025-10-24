#include "Shader.h"

#include<iostream>
#include<fstream>
#include<sstream>
#include<streambuf>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glad/glad.h>


   
    Shader::Shader(const std::shared_ptr<VertexShader>& vertexShader, const std::shared_ptr<FragmentShader>& fragmentShader)
    {
        ID = glCreateProgram();
        glAttachShader(ID, vertexShader->id);
        glAttachShader(ID, fragmentShader->id);
        glLinkProgram(ID);
        int  success;
        char infoLog[512];
        glGetProgramiv(ID, GL_COMPILE_STATUS, &success);
        if (!success) 
        {
            glGetProgramInfoLog(ID, 512, NULL, infoLog);
            std::cout << "ERROR::Program::" << "::LINK_FAILED\n" << infoLog << std::endl;
        }
    }

    size_t Shader::location(std::string name)
    {
       return glGetUniformLocation(ID, name.c_str());
    }
    void Shader::setBool(const std::string& name, bool value) const
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }
    void Shader::activate()
    {
        glUseProgram(ID);
    }
    void Shader::setMat4(std::string name, glm::mat4 value)
    {
        glUniformMatrix4fv(location(name), 1, GL_FALSE, glm::value_ptr(value));
    }
    void Shader::setFloat(std::string name, float value)
    {
        glUniform1f(location(name), value);
    }
    void Shader::setInt(std::string name, int value)
    {
        glUniform1i(location(name), value);
    }
    void Shader::setVec3(std::string name, glm::vec3 value)
    {
        glUniform3f(location(name),value.x, value.y, value.z);
    }
    Shader::~Shader()
    {
        glDeleteProgram(ID);
        std::cout << "delete shader\n";
    }


    std::string Shader::loadShaderSrc(const std::string& fileName)
    {
        std::ifstream file(fileName);
        std::stringstream buf;
        std::string ret = "";
        if (file.is_open()) {
            buf << file.rdbuf();
            ret = buf.str();
        }
        else std::cout << "Could not open " << fileName << "!!!!" << std::endl;
        file.close();
        return ret;
    }