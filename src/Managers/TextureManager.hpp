#pragma once
#include <map>
#include <memory>
#include <string>
#include "../openGL/Texture.h" 

class TextureManager {
public:
    static std::shared_ptr<Texture> get(const std::string& path);
    static void clear();

private:
    static std::map<std::string, std::shared_ptr<Texture>> textureMap;
};
