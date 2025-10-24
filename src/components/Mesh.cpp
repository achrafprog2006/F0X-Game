#include "Mesh.hpp"
#include <glad/glad.h>
#include <iostream>

Mesh::Mesh(const std::vector<float>& vertices,
    const std::vector<unsigned int>& indices,
    const std::vector<std::shared_ptr<Texture>>& textures,
    glm::vec3 diffuse)
{
    if (textures.size() > 0)
        ambientTexture = textures[0];
    else
        diffuseColor = diffuse;
   
    vao.bind();

    ebo.bind();
    ebo.fill(indices);

    vbo.bind();
    vbo.fill(vertices);

    vao.point(0, 3, GL_FLOAT, 8 * sizeof(float), 0);
    vao.enable(0);

    vao.point(1, 3, GL_FLOAT, 8 * sizeof(float), 3 * sizeof(float));
    vao.enable(1);

    vao.point(2, 2, GL_FLOAT, 8 * sizeof(float), 6 * sizeof(float));
    vao.enable(2);

    vao.unbind();

    indexCount = indices.size();
}
