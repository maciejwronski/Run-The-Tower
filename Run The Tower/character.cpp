#pragma once

#include "character.h"

character::character() {}
character::~character() {}

void character::Init() {
	x = 400;
	y = 460;
	vel[0] = 0;
	vel[1] = 0;
}
float character::getPositionX() {
	return x;
}
float character::getPositionY() {
	return y;
}
float character::getVelocityX() {
	return vel[0];
}
float character::getVelocityY() {
	return vel[1];
}
void character::setDirection(int num) {
	direction = num;
}
int character::getWidth() {
	return width;
}
int character::getHeight() {
	return height;
}
bool character::isBound() {
	return bound;
}
void character::setWidth(int pwidth) {
	width = pwidth;
}
void character::setHeight(int pheight) {
	height = pheight;
}

void character::setPositionX(float position_x) {
	x = position_x;
}
void character::setPositionY(float position_y) {
	y = position_y;
}

void character::setVelocityX(float velX) {
	vel[0] = velX;
}
void character::setVelocityY(float velY) {
	vel[1] = velY;
}

void character::startJump() {
	if (onGround)
	{
		vel[1] = -12.0;
		onGround = false;
	}
}
void character::endJump()
{
	if (vel[1] < -6.0)
		vel[1] = -6.0;
}
void character::updateJump() {
	vel[1] += 0.5;
	y += vel[1];
	x += vel[0];
	if (y > 460.0)
	{
		y = 460.0;
		vel[1] = 0.0;
		onGround = true;
		vel[0] = 0.0;
	}

	if (x <= 82|| x >= 694) { /////////// 
		vel[0] *= -1;
		bound = true; 
		if (direction == 1)
			direction = 2;
		else if (direction == 2)
			direction = 1;
	}
}

bool character::inAir() {
	return !onGround;
}
int character::getDirection() {
	return direction;
}
void character::Draw(ALLEGRO_BITMAP *bitmap) {
	al_draw_bitmap(bitmap, x, y, 0);
}