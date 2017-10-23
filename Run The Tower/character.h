#pragma once

class character {
	float x, y;
	float vel[2] = { 0.0, 0.0 };
	int width;
	int height;
	bool onGround = true;
	bool bound = false;
public:
	character(float position_x, float position_y) : x(position_x), y(position_y) {
		vel[0] = 0.0;
		vel[1] = 0.0;
	}
	bool isBound();
	bool inAir();
	float getPositionX();
	float getPositionY();
	int getWidth();
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
};