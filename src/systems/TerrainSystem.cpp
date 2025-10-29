#pragma once
#include <algorithm>
#include"../entities/Entity.h"
#include"../components/Terrain.hpp"

namespace TerrainSystem {

	float getHeightAt(const std::shared_ptr<Entity>& terrainEntity, float x, float z)
	{
		auto terrain = terrainEntity->Cterrain;
		if (!terrain) return 0.0f;

		const int size = terrain->size;
		const float spacing = terrain->spacing;
		const glm::vec3 origin = terrain->origin;

		// Convert world (x, z) to local terrain grid space
		float localX = x - origin.x;
		float localZ = z - origin.z;

		int col = static_cast<int>(localX / spacing + (size - 1) / 2.0f);
		int row = static_cast<int>(localZ / spacing + (size - 1) / 2.0f);

		// Clamp to prevent out-of-bounds
		col = std::clamp(col, 0, size - 1);
		row = std::clamp(row, 0, size - 1);

		return terrain->heightData[row][col];
	}


};