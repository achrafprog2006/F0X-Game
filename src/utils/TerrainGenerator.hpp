#pragma once
#include <vector>
#include <glm/glm.hpp>
#include<stb/stb_image.h>

namespace TerrainGenerator
{
	
    void generate(
        std::vector<float>& vertices,
        std::vector<unsigned int>& indices,
        float spacing,
        int size,
        const std::string& heightmapPath,
        std::vector<std::vector<float>>& heightData)
    {
        vertices.clear();
        indices.clear();

        // Load heightmap image (grayscale)
        int width, height, channels;
        unsigned char* data = stbi_load(heightmapPath.c_str(), &width, &height, &channels, 1);
        if (!data)
        {
            std::cerr << "Failed to load heightmap: " << heightmapPath << std::endl;
            return;
        }

        // Resize heightData 2D vector
        heightData.resize(size, std::vector<float>(size, 0.0f));

        // Temporary position and normal storage
        std::vector<glm::vec3> tempPositions(size * size);
        std::vector<glm::vec3> tempNormals(size * size, glm::vec3(0.0f));

        const float maxHeight = 50.0f;

        // First pass: generate positions and store height values
        for (int row = 0; row < size; ++row)
        {
            for (int col = 0; col < size; ++col)
            {
                float x = (col - (size - 1) / 2.0f) * spacing;
                float z = (row - (size - 1) / 2.0f) * spacing;

                int imgX = std::clamp(col * width / size, 0, width - 1);
                int imgY = std::clamp(row * height / size, 0, height - 1);
                unsigned char pixel = data[imgY * width + imgX];
                float y = (pixel / 255.0f) * maxHeight;

                tempPositions[row * size + col] = glm::vec3(x, y, z);
                heightData[row][col] = y; // Store height here
            }
        }

        // Second pass: build indices and accumulate normals
        for (int row = 0; row < size - 1; ++row)
        {
            for (int col = 0; col < size - 1; ++col)
            {
                unsigned int topLeft = row * size + col;
                unsigned int bottomLeft = (row + 1) * size + col;
                unsigned int topRight = row * size + (col + 1);
                unsigned int bottomRight = (row + 1) * size + (col + 1);

                // Triangle 1
                indices.insert(indices.end(), { topLeft, bottomLeft, topRight });
                glm::vec3 n1 = glm::normalize(glm::cross(
                    tempPositions[bottomLeft] - tempPositions[topLeft],
                    tempPositions[topRight] - tempPositions[topLeft]));
                tempNormals[topLeft] += n1;
                tempNormals[bottomLeft] += n1;
                tempNormals[topRight] += n1;

                // Triangle 2
                indices.insert(indices.end(), { topRight, bottomLeft, bottomRight });
                glm::vec3 n2 = glm::normalize(glm::cross(
                    tempPositions[bottomRight] - tempPositions[topRight],
                    tempPositions[bottomLeft] - tempPositions[topRight]));
                tempNormals[topRight] += n2;
                tempNormals[bottomLeft] += n2;
                tempNormals[bottomRight] += n2;
            }
        }

        // Final pass: write vertex attributes (pos, normal, uv)
        for (int row = 0; row < size; ++row)
        {
            for (int col = 0; col < size; ++col)
            {
                int idx = row * size + col;
                glm::vec3 pos = tempPositions[idx];
                glm::vec3 normal = glm::normalize(tempNormals[idx]);

                float u = static_cast<float>(col) / (size - 1) * 30.0f;
                float v = static_cast<float>(row) / (size - 1) * 30.0f;

                vertices.insert(vertices.end(), {
                    pos.x, pos.y, pos.z,
                    normal.x, normal.y, normal.z,
                    u, v
                    });
            }
        }

        stbi_image_free(data);
    }
}


