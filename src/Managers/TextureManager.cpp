#include "TextureManager.hpp"

std::map<std::string, std::shared_ptr<Texture>> TextureManager::textureMap;

std::shared_ptr<Texture> TextureManager::get(const std::string& path) {
    auto& texture = textureMap[path];
    if (!texture)
    {
        texture = std::make_shared<Texture>(path.c_str());
    }
    return texture;
}

void TextureManager::clear() {
    textureMap.clear();
}
