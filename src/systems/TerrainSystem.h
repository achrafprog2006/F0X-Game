#pragma once
#include"../entities/Entity.h"
#include<memory>

namespace TerrainSystem {

	float getHeightAt(const std::shared_ptr<Entity>& terrainEntity, float x, float z);

};