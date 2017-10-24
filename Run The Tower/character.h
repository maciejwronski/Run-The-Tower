#pragma once

#include "includes.h"

class character {
	float x, y;
	float vel[2] = { 0.0, 0.0 };
	int width;
	int height;
	bool onGround = true;
	bool bound = false;
	int direction = 1; // 1 - left, 2 right
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
	void startJump();
	void endJump();
	void updateJump();
	void Draw(ALLEGRO_BITMAP *bitmap);
};