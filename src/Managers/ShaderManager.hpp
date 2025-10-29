#pragma once
#include <map>
#include <memory>
#include <string>
#include "../shaders/Shader.h" 



class ShaderManager {
public:
    static void init();
    static  const std::shared_ptr<Shader>& get(const std::string& name);
    static void clear();

private:
    static std::map<std::string, std::shared_ptr<Shader>> shaderMap;
};
