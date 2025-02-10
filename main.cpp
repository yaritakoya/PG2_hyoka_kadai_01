#include <Novice.h>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "math.h"

const char kWindowTitle[] = "LC1C_23_ヤリタ_コウヤ_タイトル";

Scene scene = TITLE;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Player* player = new Player();
	Enemy* enemy = new Enemy();

	float distance1 = 0.0f;
	float distance2 = 0.0f;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		if (scene == PLAY) {
			player->Update(keys, preKeys);
			enemy->Update();
			//距離の計算
			distance2 = sqrtf(
				(enemy->GetPos().x - player->GetPos().x) * (enemy->GetPos().x - player->GetPos().x) +
				(enemy->GetPos().y - player->GetPos().y) * (enemy->GetPos().y - player->GetPos().y));
			distance1 = sqrtf(
				(enemy->GetPos().x - player->GetBullet()->GetPos().x) * (enemy->GetPos().x - player->GetBullet()->GetPos().x) +
				(enemy->GetPos().y - player->GetBullet()->GetPos().y) * (enemy->GetPos().y - player->GetBullet()->GetPos().y));

			if (distance2 <= player->GetRadiuse().x + enemy->GetRadiuse().x) {
				player->SetIsAlive(false);
			}

			if (distance1 <= player->GetBullet()->GetRadiuse().x + enemy->GetRadiuse().x) {
				player->GetBullet()->SetIsHit(false);
				enemy->SetIsAlive(false);
			}
		}
		
		switch (scene) {
		case TITLE:
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = PLAY;
				//player
				player->SetPos({ 640.0f,360.0f });
				player->SetRadius({ 40.0f,40.0f });
				player->SetDistance({ 0.0f });
				player->SetSpeed(20);
				player->SetIsShot(false);
				player->SetIsAlive(true);
				//enemy
				enemy->SetPos({ 640.0f,80.0f });
				enemy->SetRadius({ 40.0f,40.0f });
				enemy->SetDistance(0.0f);
				enemy->SetSpeed(10);
				enemy->SetRespawnCount(0);
				enemy->SetIsAlive(true);
				//
				distance1 = 0.0f;
				distance2 = 0.0f;
			}
			Novice::ScreenPrintf(0, 0, "title");
			break;
		case PLAY:
			if (player->GetIsAlive() == 0) {
				scene = GAMEOVER;
			}
			if (enemy->GetRespawnCount() > 3) {
				scene = CLEAR;
			}
			Novice::ScreenPrintf(0, 0, "play");
			break;
		case CLEAR:
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = TITLE;
			}
			Novice::ScreenPrintf(0, 0, "clear");
			break;
		case GAMEOVER:
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				scene = TITLE;
			}
			Novice::ScreenPrintf(0, 0, "gameover");
			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		if (scene == PLAY) {
			player->Draw();
			enemy->Draw();

		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
