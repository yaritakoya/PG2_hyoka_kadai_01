#include <Novice.h>
#include "Player.h"
#include "Bullet.h"

Bullet::Bullet() {
	pos_ = { -1200.0f,-1200.0f };
	radius_ = { 20.0f,20.0f };
	distance_ = 0.0f;
	speed_ = 10;
	isShot_ = false;
	isHit_ = false;
}

Bullet::~Bullet() {

}

void Bullet::Update() {
	if (isShot_ != 0) {
		pos_.y -= speed_;
		if (pos_.y < 0) {
			isShot_ = false;
		}
	}
}

void Bullet::Draw() {
	if (isShot_ != 0) {
		if (isHit_ == 0) {
			Novice::DrawEllipse(
				int(pos_.x), int(pos_.y), int(radius_.x), int(radius_.y), 0.0f,
				RED, kFillModeSolid);
		}
	}
}

