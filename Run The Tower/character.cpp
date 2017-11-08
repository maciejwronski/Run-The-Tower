#include "character.h"
#include <iostream>
character::character() {}
character::~character() {}

void character::Init() {
	x = 400;
	y = 460;
	vel[0] = 0;
	vel[1] = 0;
	score = 0;
	player_left = al_load_bitmap("player_images/left.png");
	player_right = al_load_bitmap("player_images/right.png");
	font = al_load_font("fonts/times.ttf", 24, 0);
	width = al_get_bitmap_width(player_left);
	height = al_get_bitmap_height(player_left);
}
/*/           GETTERS           /*/ 
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
int character::getWidth() {
	return width;
}
int character::getHeight() {
	return height;
}
int character::getDirection() {
	return direction;
}
/*             SETTERS          */
void character::setDirection(int num) {
	direction = num;
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

void character::setDuration(double dur) {
	duration = dur;
}
/*         MOVEMENT         */
void character::moveRight(block&Block, character& player) {
	if (Block.CheckIfPlayerIsFlying(player) && !jumped && !falling) {
		vel[1] = 0;
		vel[0] = 0;
		falling = true;
	}
	temp1 = 10 * duration*run_boost;
	temp2 = x + temp1;
	vel[0] = temp1*0.5;
	x = temp2;
	start = std::clock();
}
void character::moveLeft(block&Block, character& player) {
	if (Block.CheckIfPlayerIsFlying(player) && !jumped && !falling) {
		vel[1] = 0;
		vel[0] = 0;
		falling = true;
	}
	temp1 = -10 * duration*run_boost;
	temp2 = x + temp1;
	vel[0] = temp1*0.5;
	x = temp2;
	start = std::clock();
}

void character::startJump(map& Map, character& player) {
	if (onGround)
	{
		vel[1] = -11.0;
		onGround = false;
		jumped = true;
	}
}
void character::updateJump(block& Block, character& player) {
	if (!onGround || falling) {
		if (vel[1] < 0)
			vel[1] += up_gravity;
		else
			vel[1] += falling_gravity;
		y += vel[1];
		x += vel[0];
		if (vel[1] > 0) {
			Block.CollidingWithPlayer(player);
			jumped = false;
		}
	}
	if (y > 460){
		y = 460;
		vel[1] = 0.0;
		onGround = true;
		vel[0] = 0.0;
		jumped = false;
		falling = false;
	}

	if ((x + width >= START_OF_RIGHT_WALL && x <= WALL_WIDTH + START_OF_RIGHT_WALL) || (x + width >= START_OF_LEFT_WALL &&x <= START_OF_LEFT_WALL + WALL_WIDTH)){
	vel[0] *= -1;
	bound = true;
	if (direction == 1)
		direction = 2;
	else if (direction == 2)
		direction = 1;
	}
}
void character::DrawCharacter(int direction) {
	switch (direction) {
	case 1:
		al_draw_bitmap(player_left, x, y, 0);
		break;
	case 2:
		al_draw_bitmap(player_right, x, y, 0);
		break;
	}
	flipDisplay();
}
void character::flipDisplay() {
	al_flip_display();
}
/*          BOOLS        */
bool character::isBound() {
	return bound;
}
bool character::inAir() {
	return !onGround;
}