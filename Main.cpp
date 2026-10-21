#include "DxLib.h"
#include "Map.h"
#include "Camera.h"
#include "Player.h" 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    ChangeWindowMode(TRUE);

    if (DxLib_Init() == -1) {
        return -1;
    }

    SetDrawScreen(DX_SCREEN_BACK);

    SetUseZBuffer3D(TRUE);
    SetWriteZBuffer3D(TRUE);

    // クラスのインスタンス化
    Map stageMap;
    Camera gameCamera;
    Player player; // プレイヤーを作成

    while (ProcessMessage() == 0 && ClearDrawScreen() == 0) {

        // --- 1. 更新処理 ---
        player.Update();                                // プレイヤーの移動入力
        gameCamera.Update(player.GetPos());             // プレイヤーの位置にカメラを追従

        // --- 2. 3D描画処理 ---
        stageMap.Draw();                                // 床の描画
        player.Draw();                                  // プレイヤーの描画

        // 2D UI描画
        DrawString(20, 20, "DxLib 3D Avoid Game", GetColor(255, 255, 255));
        DrawString(20, 40, "W/A/S/D: Move | SPACE: Jump", GetColor(200, 200, 200));
        DrawString(20, 60, "ESC key: Exit", GetColor(200, 200, 200));
        ScreenFlip();

        if (CheckHitKey(KEY_INPUT_ESCAPE)) {
            break;
        }
    }

    DxLib_End();
    return 0;
}