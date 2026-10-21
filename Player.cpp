#include "Player.h"

Player::Player() {
    pos = VGet(0.0f, 0.0f, 0.0f);
    speed = 4.0f;
    radius = 30.0f;

    jumpPower = 9.0f;  // ジャンプの勢い
    velocityY = 0.0f;  // 縦方向の速度
    isJumping = false; // 最初は地上にいる
}

void Player::Update() {
    // --- 1. WASDキーによる平面移動 ---
    if (CheckHitKey(KEY_INPUT_W) || CheckHitKey(KEY_INPUT_UP)) {
        pos.z += speed;
    }
    if (CheckHitKey(KEY_INPUT_S) || CheckHitKey(KEY_INPUT_DOWN)) {
        pos.z -= speed;
    }
    if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT)) {
        pos.x -= speed;
    }
    if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT)) {
        pos.x += speed;
    }

    // --- 2. スペースキーによるジャンプ処理 ---
    // 地上にいる時だけスペースキーでジャンプできる
    if (CheckHitKey(KEY_INPUT_SPACE) && !isJumping) {
        velocityY = jumpPower; // 上方向へ初速をつける
        isJumping = true;      // ジャンプ中フラグをON
    }

    // --- 3. 重力とジャンプの縦移動計算 ---
    if (isJumping) {
        pos.y += velocityY;     // Y座標（高さ）を更新
        velocityY -= 0.25f;      // 重力によって下向きに速度が減っていく（引っ張られる）

        // 床（高さ0.0f）に着地した判定
        if (pos.y <= 0.0f) {
            pos.y = 0.0f;       // 床の位置に固定
            velocityY = 0.0f;   // 速度をリセット
            isJumping = false;  // 地面に戻る
        }
    }
}

void Player::Draw() {
    // 赤い球体として描画（ジャンプするとY座標が変わるので立体的に浮き上がります）
    DrawSphere3D(pos, radius, 16, GetColor(255, 50, 50), GetColor(255, 255, 255), TRUE);
}

VECTOR Player::GetPos() const {
    return pos;
}