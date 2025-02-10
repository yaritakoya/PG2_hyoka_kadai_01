#include "Player.h"
#include "Bullet.h"

Player::Player() {
	pos_ = { 640.0f,360.0f };
	radius_ = { 40.0f,40.0f };
	distance_ = 0.0f;
	speed_ = 20;
	isShot_ = false;
	isAlive_ = true;
	bullet = new Bullet();
}

Player::~Player() {

}

void Player::Update(char* keys, char* preKeys) {

#pragma region 移動処理

	if (keys[DIK_W]) {
		pos_.y -= speed_;
		if (pos_.y - radius_.y < 0.0f) {
			pos_.y += speed_;
		}
	}

	if (keys[DIK_A]) {
		pos_.x -= speed_;
		if (pos_.x - radius_.x < 0.0f) {
			pos_.x += speed_;
		}
	}

	if (keys[DIK_S]) {
		pos_.y += speed_;
		if (pos_.y + radius_.y > 720.0f) {
			pos_.y -= speed_;
		}
	}

	if (keys[DIK_D]) {
		pos_.x += speed_;
		if (pos_.x + radius_.x > 1280.0f) {
			pos_.x -= speed_;
		}
	}

#pragma endregion

	//発射処理
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {
		if (bullet->GetIsShot() == 0) {
			bullet->SetIsShot(true);
			bullet->SetPos(pos_);
		}
	}

	bullet->Update();
}

void Player::Draw() {
	bullet->Draw();
	if (isAlive_ != 0) {
		Novice::DrawEllipse(
			int(pos_.x), int(pos_.y), int(radius_.x), int(radius_.y),
			0.0f, WHITE, kFillModeSolid);
		Novice::DrawEllipse(
			int(pos_.x), int(pos_.y), int(radius_.x), int(radius_.y),
			0.0f, BLACK, kFillModeWireFrame);
	}
}

