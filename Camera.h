#pragma once
#include "DxLib.h"

class Camera 
{
public:
    Camera();
    // プレイヤーの位置を受け取ってカメラを動かす関数
    void Update(VECTOR playerPos);
};