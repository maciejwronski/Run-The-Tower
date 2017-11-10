#pragma once

#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <ctime>
#include "map.h"
#include "block.h"

static int temp1, temp2;

static float run_boost = 0.8; // used for run-boost
static float up_gravity = 0.45;
static float falling_gravity = 0.2;
static float block_point = 10;
static clock_t start; //

class character {
	friend class block;
	friend class camera;
	bool keys[5] = { false };
	enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE };
	friend class block;
	friend class map;
	bool jumped;

	float x, y;
	float vel[2] = { 0.0, 0.0 };
	int width;
	int height;
	bool falling;
	bool onGround = true;
	bool bound = false;
	double duration;
	int direction = 1; // 1 - left, 2 right
	int score = 0;

	ALLEGRO_BITMAP *player_left = NULL;
	ALLEGRO_BITMAP *player_right = NULL;
	ALLEGRO_FONT *font = NULL;
public:
	character();
	~character();
	void Init();
	float getPositionX();
	float getPositionY();
	int getWidth();
	int getDirection();
	int getHeight();
	float getVelocityX();
	float getVelocityY();
	void setDirection(int num);
	void setPositionX(float position_x);
	void setPositionY(float position_y);
	void setVelocityX(float velX);
	void setVelocityY(float velY);
	void setDuration(double dur);
	void DrawScore(float* CameraPosition);
	void updateScore(character& player, int i);
	void startJump(map& Map, character& player);
	void updateJump(block& Block, character& player);
	void DrawCharacter(int direction, float* CameraPosition);
	void moveRight(block&Block, character& player);
	void moveLeft(block&Block, character& player);
	void flipDisplay();
	bool isBound();
	bool inAir();
};