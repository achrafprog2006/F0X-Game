#pragma once

#include "../openGL/Vao.h"
#include "../openGL/Vbo.h"
#include "../openGL/Ebo.h"
#include "../openGL/Texture.h"
#include "../shaders/Shader.h"
#include <memory>
#include <vector>

struct Mesh
{
    Vao vao;
    Vbo vbo;
    Ebo ebo;
    std::shared_ptr<Shader> shader;
    std::shared_ptr<Texture> ambientTexture;
    glm::vec3 diffuseColor;
    unsigned int indexCount;

    Mesh(const std::vector<float>& vertices,
        const std::vector<unsigned int>& indices,
        const std::vector<std::shared_ptr<Texture>>& textures,
        glm::vec3 diffuse);
};
