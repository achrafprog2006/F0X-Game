#include "RenderSystem.h"

#include<iostream>
#include"../Managers/ShaderManager.hpp"
#include<glad/glad.h>

namespace RenderSystem
{
    void init() {

    }

    void render(const std::shared_ptr<Entity>& entity)
    {
        int i = 0;
       if (entity->CstaticMesh)
        {
            auto shader = entity->Cshader;
            // Bind shader, set uniforms, bind VAO, draw call, etc.
            shader->activate();

            if (entity->Ctransform)
                shader->setMat4("transformationMat", entity->Ctransform->transformationMatrix);
            else
                shader->setMat4("transformationMat", glm::mat4(1.0f));

            entity->CstaticMesh->ambientTexture->activateOn(0);
            shader->setInt("ambientTexture", 0);
            shader->setBool("uTexture", true);
            entity->CstaticMesh->vao.bind();
            glDrawElements(GL_TRIANGLES, entity->CstaticMesh->indexCount, GL_UNSIGNED_INT, nullptr);
            entity->CstaticMesh->vao.unbind();
        }

    }

    void render(const std::vector<std::shared_ptr<Entity>>& entities)
    {
        for (auto entity : entities)
            render(entity);
    }


    void cleanup()
    {
        // Cleanup GPU resources if needed
    }

}

