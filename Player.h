#pragma once
#include "DxLib.h"

class Player {
private:
    VECTOR pos;     // プレイヤーの現在地 (x, y, z)
    float speed;    // 移動スピード
    float radius;   // 半径

    // ジャンプ用の変数
    float jumpPower; // ジャンプの初速
    float velocityY; // 現在のY方向の速度
    bool isJumping;  // ジャンプ中かどうか

public:
    Player();
    void Update();
    void Draw();

    VECTOR GetPos() const;
};