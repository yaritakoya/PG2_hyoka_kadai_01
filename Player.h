#pragma once
#include <Novice.h>
#include "Vector2.h"
#include "Bullet.h"

class Player {
public:
	Player();
	~Player();

	void Update(char* keys, char* preKeys);
	void Draw();
	//セッター
	void SetPos(Vector2 pos) { pos_ = pos; }
	void SetRadius(Vector2 radius) { radius_ = radius; }
	void SetDistance(float distance) { distance_ = distance; }
	void SetSpeed(int speed) { speed_ = speed; }
	void SetIsShot(int isShot) { isShot_ = isShot; }
	void SetIsAlive(int isAlive) { isAlive_ = isAlive; }
	//ゲッター
	Vector2 GetPos() { return pos_; }
	Vector2 GetRadiuse() { return radius_; }
	float GetDistance() { return distance_; }
	int GetSpeed() { return speed_; }
	int GetIsShot() { return isShot_; }
	int GetIsAlive() { return isAlive_; }
	Bullet* GetBullet() { return bullet; }

private:
	Vector2 pos_;
	Vector2 radius_;
	float distance_;
	int speed_;
	int isShot_;
	int isAlive_;
	Bullet* bullet;
};

