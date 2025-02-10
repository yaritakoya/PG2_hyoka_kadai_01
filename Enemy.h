#pragma once
#include <Novice.h>
#include "Vector2.h"
#include "Player.h"
#include "Bullet.h"

class Enemy {
public:
	Enemy();
	~Enemy();

	void Update();
	void Draw();
	//セッター
	void SetPos(Vector2 pos) { pos_ = pos; }
	void SetRadius(Vector2 radius) { radius_ = radius; }
	void SetDistance(float distance) { distance_ = distance; }
	void SetSpeed(int speed) { speed_ = speed; }
	void SetIsAlive(int isAlive) { isAlive_ = isAlive; }
	void SetRespawnCount(int respawnCount) {
		respawnCount_ = respawnCount;
	}
	//ゲッター
	Vector2 GetPos() { return pos_; }
	Vector2 GetRadiuse() { return radius_; }
	float GetDistance() { return distance_; }
	int GetSpeed() { return speed_; }
	int GetRespawnCount() { return respawnCount_; }
	int GetIsAlive() { return isAlive_; }

private:
	Vector2 pos_;
	Vector2 radius_;
	float distance_;
	int speed_;
	int respawntimer_;
	int timerFlag_;
	int respawnCount_;
	int isAlive_;
};

