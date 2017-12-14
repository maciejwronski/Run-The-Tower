#pragma once

#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <ctime>
#include "block.h"
#include "map.h"
#include "camera.h"

static int temp1, temp2; // used for acceleration

static float run_boost = 0.8; // used for run-boost
static float up_gravity = 0.45; // Gravity for player, when jumped
static float falling_gravity = 0.2; // Gravity, when player's falling
static float block_point = 10; // Point for passing single block
static clock_t start;

class Character {
	friend class Block;
	friend class Camera;
	friend class Map;

	bool jumped;
	bool falling;
	bool onGround = true;
	bool bound = false;

	float coordinateX, coordinateY;
	float velocity[2];
	float bitmapWidth;
	float bitmapHeight;

	double keyTimeHold;

	int movingInDirection;
	int totalScore;
	int bonusPoints;

	ALLEGRO_BITMAP *player_left;
	ALLEGRO_BITMAP *player_right;
	ALLEGRO_FONT *font;
public:
	Character();
	~Character();
	bool isBound();
	bool inAir();
	int getDirection();
	int getScore();
	int getBonusPoints();
	float getPositionX();
	float getPositionY();
	float getVelocityX();
	float getVelocityY();
	float getWidth();
	float getHeight();
	void setDirection(int num);
	void setPositionX(float position_x);
	void setPositionY(float position_y);
	void setVelocityX(float velX);
	void setVelocityY(float velY);
	void setDuration(double dur);
	void addBonusPoints(int num);
	void drawScore(float* CameraPosition);
	void updateScore(Character& player, int i);
	void startJump();
	void updateJump(Block& Block, Character& player);
	void drawCharacter(int direction, float* CameraPosition);
	void moveRight(Block&Block, Character& player);
	void moveLeft(Block&block, Character& player);
	void flipDisplay();
};