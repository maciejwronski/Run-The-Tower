#include "character.h"
#include <iostream>
Character::Character() {
	x = 400;
	y = 460;
	vel[0] = 0;
	vel[1] = 0;
	score = 0;
	direction = 1;
	score = 0;
	player_left = al_load_bitmap("player_images/left.png");
	player_right = al_load_bitmap("player_images/right.png");
	font = al_load_font("fonts/times.ttf", 24, 0);
	width = al_get_bitmap_width(player_left);
	height = al_get_bitmap_height(player_left);
}
Character::~Character() {
	al_destroy_bitmap(player_left);
	al_destroy_bitmap(player_right);
	al_destroy_font(font);
}
/*/           GETTERS           /*/ 
float Character::getPositionX() {
	return x;
}
float Character::getPositionY() {
	return y;
}
float Character::getVelocityX() {
	return vel[0];
}
float Character::getVelocityY() {
	return vel[1];
}
int Character::getWidth() {
	return width;
}
int Character::getHeight() {
	return height;
}
int Character::getScore()
{
	return score;
}
int Character::getDirection() {
	return direction;
}
/*             SETTERS          */
void Character::setDirection(int num) {
	direction = num;
}

void Character::setPositionX(float position_x) {
	x = position_x;
}
void Character::setPositionY(float position_y) {
	y = position_y;
}

void Character::setVelocityX(float velX) {
	vel[0] = velX;
}
void Character::setVelocityY(float velY) {
	vel[1] = velY;
}

void Character::setDuration(double dur) {
	duration = dur;
}
/*         MOVEMENT         */
void Character::moveRight(Block&block, Character& player) {
	if (block.CheckIfPlayerIsFlying(player) && !jumped && !falling) {
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
void Character::moveLeft(Block&block, Character& player) {
	if (block.CheckIfPlayerIsFlying(player) && !jumped && !falling) {
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

void Character::startJump() {
	if (onGround)
	{
		vel[1] = -11.0;
		onGround = false;
		jumped = true;
	}
}
void Character::updateJump(Block& block, Character& player) {
	if (!onGround || falling) {
		if (vel[1] < 0)
			vel[1] += up_gravity;
		else
			vel[1] += falling_gravity;
		y += vel[1];
		x += vel[0];
		if (vel[1] >= 0) {
			block.CollidingWithPlayer(player);
		}
	}
	if (y > 460){
		y = 460;
		vel[0] = 0.0;
		vel[1] = 0.0;
		onGround = true;
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
void Character::updateScore(Character&player, int i) {
	if (player.score / block_point <= i)
		player.score = i * block_point;
}
void Character::DrawScore(float* CameraPosition) {
	al_draw_textf(font, al_map_rgb(255, 128, 0), 130+CameraPosition[0], 500+CameraPosition[1], ALLEGRO_ALIGN_CENTRE, "Score: %d", score);
}
void Character::DrawCharacter(int direction, float* CameraPosition) {
	switch (direction) {
	case 1:
		al_draw_bitmap(player_left, x, y, 0);
		break;
	case 2:
		al_draw_bitmap(player_right, x, y, 0);
		break;
	}
	DrawScore(CameraPosition);
	flipDisplay();
}
void Character::flipDisplay() {
	al_flip_display();
}
/*          BOOLS        */
bool Character::isBound() {
	return bound;
}
bool Character::inAir() {
	return !onGround;
}