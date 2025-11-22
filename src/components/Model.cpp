#include "Model.hpp"

#include"../Managers/TextureManager.hpp"
#include<iostream>
#include <assimp/Importer.hpp>
#include<assimp/postprocess.h>


Model::Model(const std::string& path)
{
    Assimp::Importer importer;
    std::cout << "loading model....\n";
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_CalcTangentSpace);// |aiProcess_FlipUVs
    std::cout << "model loaded !!!!!!\n";

    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cerr << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
        return;
    }

    directory = path.substr(0, path.find_last_of('/'));
    processNode(scene->mRootNode, scene, glm::mat4(1.0f));
}




void Model::processNode(aiNode* node, const aiScene* scene, const glm::mat4& parentTransform)
{
    glm::mat4 nodeTransform = parentTransform * AssimpToGLM(node->mTransformation);
    for (unsigned int i = 0; i < node->mNumMeshes;i++) 
    {
        //std::cout << " mesh!!!!!!\n";
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene, nodeTransform));
    }

    for (unsigned int i = 0; i < node->mNumChildren; ++i)
    {
        processNode(node->mChildren[i], scene, nodeTransform);
    }
}


std::shared_ptr<Mesh> Model::processMesh(aiMesh* mesh, const aiScene* scene, const glm::mat4& nodeTransform)
{
    std::vector<float> vertexData;
    std::vector<unsigned int> indices;
    glm::vec4 v(0, 0, 0, 1);

    for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
        // Position
        v.x = mesh->mVertices[i].x;
        v.y = mesh->mVertices[i].y;
        v.z = mesh->mVertices[i].z;
        v.w = 1;
        v = nodeTransform * v;
        vertexData.push_back(v.x);
        vertexData.push_back(v.y);
        vertexData.push_back(v.z);

        // Normal
        vertexData.push_back(mesh->mNormals[i].x);
        vertexData.push_back(mesh->mNormals[i].y);
        vertexData.push_back(mesh->mNormals[i].z);

        // TexCoords
        if (mesh->mTextureCoords[0]) {
            vertexData.push_back(mesh->mTextureCoords[0][i].x);
            vertexData.push_back(mesh->mTextureCoords[0][i].y);
        }
        else {
            vertexData.push_back(0.0f);
            vertexData.push_back(0.0f);
        }
        // more: tangents, bitangents, bone weights if needed
    }
    //----------------indices----------------
    for (unsigned int i = 0; i < mesh->mNumFaces; ++i) {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; ++j)
            indices.push_back(face.mIndices[j]);
    }
    //------------------mtl----------------------
    std::vector< std::shared_ptr<Texture>> textures;
    glm::vec3 diffuseColor;
   // std::cout << "loading mtl.........\n";
    if (mesh->mMaterialIndex >= 0) {
        aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
        aiString str;

        bool hasTexture = false;

        if (material->GetTexture(aiTextureType_DIFFUSE, 0, &str) == AI_SUCCESS) {
            std::string path = str.C_Str();
            std::shared_ptr<Texture> diffuseTex = TextureManager::get(directory + "/" + path);
            textures.push_back(diffuseTex);
            hasTexture = true;

        }

        if (!hasTexture) {
            aiColor3D kd(0.f, 0.f, 0.f);
            if (material->Get(AI_MATKEY_COLOR_DIFFUSE, kd) == AI_SUCCESS) {
                diffuseColor = glm::vec3(kd.r, kd.g, kd.b);
            }
        }
    }

    return std::make_shared<Mesh>(vertexData, indices, textures,diffuseColor);
}