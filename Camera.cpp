#include "Camera.h"

Camera::Camera() {}

void Camera::Update(VECTOR playerPos) 
{
    // プレイヤーの少し上＆後ろにカメラを配置する
    VECTOR cameraPos = VGet(playerPos.x, playerPos.y + 150.0f, playerPos.z - 250.0f);
    VECTOR cameraTarget = VGet(playerPos.x, playerPos.y + 20.0f, playerPos.z + 50.0f);

    SetCameraPositionAndTarget_UpVecY(cameraPos, cameraTarget);
}