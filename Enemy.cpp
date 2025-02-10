#include "Enemy.h"

Enemy::Enemy() {
	pos_ = { 640.0f,80.0f };
	radius_ = { 40.0f,40.0f };
	distance_ = 0.0f;
	speed_ = 10;
	respawntimer_ = 60;
	timerFlag_ = false;
	respawnCount_ = 0;
	isAlive_ = true;
}

Enemy::~Enemy() {

}

void Enemy::Update() {
	//移動処理
	if (isAlive_ != 0) {
		pos_.x += speed_;
		if (pos_.x - radius_.x < 0.0f || pos_.x + radius_.x > 1280.0f) {
			speed_ = -speed_;
		}
	}
	if (isAlive_ == 0) {
		timerFlag_ = true;
	}
	//リスポーン処理
	if (timerFlag_ != 0) {
		if (respawntimer_ >= 60) {
			respawnCount_++;
		}
		respawntimer_--;
		if (respawntimer_ <= 0) {
			isAlive_ = true;
			timerFlag_ = false;
			respawntimer_ = 60;
		}
	}
}

void Enemy::Draw() {
	if (isAlive_ != 0) {
		Novice::DrawEllipse(
			int(pos_.x), int(pos_.y), int(radius_.x), int(radius_.y),
			0.0f, 0xAAAAAAFF, kFillModeSolid);
		Novice::DrawEllipse(
			int(pos_.x), int(pos_.y), int(radius_.x), int(radius_.y),
			0.0f, WHITE, kFillModeWireFrame);
	}
}