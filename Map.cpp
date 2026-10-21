#include "Map.h"

Map::Map() {}

void Map::Draw() 
{
    // 床の中心を Z=0.0f にして、ボールの足元に合わせる
    VECTOR centerPos = VGet(0.0f, -5.0f, 0.0f);
    VECTOR size = VGet(400.0f, 10.0f, 800.0f);

    DrawCube3D(centerPos, size, GetColor(70, 70, 80), GetColor(50, 50, 60), TRUE);
}