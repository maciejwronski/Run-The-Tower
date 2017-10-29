#pragma once

#include <allegro5\allegro_primitives.h>
#include <ctime>
static int temp1, temp2;

static float run_boost = 0.8; // used for run-boost
static clock_t start; //

class character {
	float x, y;
	float vel[2] = { 0.0, 0.0 };
	int width;
	int height;
	bool onGround = true;
	bool bound = false;
	double duration;
	int direction = 1; // 1 - left, 2 right

	ALLEGRO_BITMAP *player_left = NULL;
	ALLEGRO_BITMAP *player_right = NULL;

public:
	character();
	~character();
	void Init();
	bool isBound();
	bool inAir();
	float getPositionX();
	float getPositionY();
	int getWidth();
	void setDirection(int num);
	int getDirection();
	int getHeight();
	float getVelocityX();
	float getVelocityY();
	void setPositionX(float position_x);
	void setPositionY(float position_y);
	void setVelocityX(float velX);
	void setVelocityY(float velY);
	void setWidth(int pwidth);
	void setHeight(int pheight);
	void setDuration(double dur);
	void startJump();
	void endJump();
	void updateJump();
	void Draw(int direction);
	void moveRight();
	void moveLeft();
	void holdingKey();
	void flipDisplay();
};