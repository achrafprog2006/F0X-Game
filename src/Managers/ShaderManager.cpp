
#include "ShaderManager.hpp"
#include "../shaders/VertexShader.h" 
#include "../shaders/FragmentShader.h" 
#include<iostream>
#include <fstream>
#include<string>

     std::map<std::string, std::shared_ptr<Shader>> ShaderManager::shaderMap;

     const std::shared_ptr<Shader>& ShaderManager::get(const std::string& name) {
         auto& shader = shaderMap[name];
         if (!shader)
         {
             std::cout << "makaynch " << name << "\n";
             auto vertex = std::make_shared<VertexShader>("../src/shaders/vertex.glsl");
             auto fragment = std::make_shared<FragmentShader>("../src/shaders/fragment.glsl");
             shader = std::make_shared<Shader>(vertex, fragment);
         }
         return shader;
     }

     void ShaderManager::clear() {
         shaderMap.clear();
     }

     void ShaderManager::init()
     {
         std::string prog,vertex,fragment;
         std::ifstream file("../shaders/shader_programs.txt");
         while (file >> prog)
         {
             file >> vertex >> fragment;
             auto vertexShader = std::make_shared<VertexShader>(vertex);
             auto fragmentShader = std::make_shared<FragmentShader>(fragment);
             shaderMap[prog] = std::make_shared<Shader>(vertexShader, fragmentShader);
             std::cout << "shader_program : " << prog << " loaded .....\n";
         }
     }
