#pragma once
#include"../openGL/Vao.h"
#include"../openGL/Vbo.h"
#include"../openGL/Ebo.h"
#include"../openGL/Texture.h"
#include"../shaders/Shader.h"
#include"../shaders/VertexShader.h"
#include"../shaders/FragmentShader.h"
#include<iostream>
#include<vector>
#include<memory>


struct StaticMesh {

    Vao vao;
    Vbo vbo;
    Ebo ebo;
    std::shared_ptr<Texture> ambientTexture;
    unsigned int indexCount;


    StaticMesh(const std::vector<float>& vertices,
        const std::vector<unsigned int>& indices,
        const std::shared_ptr<Texture>& texture)
        : ambientTexture(texture)
    {
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



   
};
