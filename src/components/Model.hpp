#pragma once

#include <assimp/scene.h>
#include <glm/glm.hpp>

#include"Mesh.hpp"
#include<vector>
#include<memory>


class Model
{
public:
    std::vector<std::shared_ptr<Mesh>> meshes;
    std::string directory;

    struct Vertex {
        glm::vec3 position;
        glm::vec3 normal;
        glm::vec2 texCoords;
        // tangents, bitangents, bone IDs, weights if animated
    };

    Model(const std::string& path);

    std::shared_ptr<Mesh> processMesh(aiMesh* mesh, const aiScene* scene, const glm::mat4& nodeTransform);

    void processNode(aiNode* node, const aiScene* scene, const glm::mat4& parentTransform);

     
     inline glm::mat4 AssimpToGLM(const aiMatrix4x4& mat) {
         glm::mat4 result;
         result[0][0] = mat.a1; result[1][0] = mat.a2; result[2][0] = mat.a3; result[3][0] = mat.a4;
         result[0][1] = mat.b1; result[1][1] = mat.b2; result[2][1] = mat.b3; result[3][1] = mat.b4;
         result[0][2] = mat.c1; result[1][2] = mat.c2; result[2][2] = mat.c3; result[3][2] = mat.c4;
         result[0][3] = mat.d1; result[1][3] = mat.d2; result[2][3] = mat.d3; result[3][3] = mat.d4;
         return result;
     }

};