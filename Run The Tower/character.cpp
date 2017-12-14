#include "character.h"
#include <iostream>


Character::Character() {
	coordinateX = 400;
	coordinateY = 460;

	velocity[0] = 0;
	velocity[1] = 0;
	totalScore = 0;
	movingInDirection = 1;
	bonusPoints = 0;
	player_left = al_load_bitmap("player_images/left.png");
	player_right = al_load_bitmap("player_images/right.png");
	font = al_load_font("fonts/times.ttf", 24, 0);
	bitmapWidth = al_get_bitmap_width(player_left);
	bitmapHeight = al_get_bitmap_height(player_left);
}

Character::~Character() {
	al_destroy_bitmap(player_left);
	al_destroy_bitmap(player_right);
	al_destroy_font(font);
}
/*/           GETTERS           /*/ 
float Character::getPositionX() {
	return coordinateX;
}

float Character::getPositionY() {
	return coordinateY;
}

float Character::getVelocityX() {
	return velocity[0];
}

float Character::getVelocityY() {
	return velocity[1];
}

float Character::getWidth() {
	return bitmapWidth;
}

float Character::getHeight() {
	return bitmapHeight;
}

int Character::getScore(){
	return totalScore;
}

int Character::getBonusPoints(){
	return bonusPoints;
}
int Character::getDirection() {
	return movingInDirection;
}

/*             SETTERS          */
void Character::setDirection(int num) {
	movingInDirection = num;
}

void Character::setPositionX(float position_x) {
	coordinateX = position_x;
}

void Character::setPositionY(float position_y) {
	coordinateY = position_y;
}

void Character::setVelocityX(float velX) {
	velocity[0] = velX;
}

void Character::setVelocityY(float velY) {
	velocity[1] = velY;
}

void Character::setDuration(double dur) {
	keyTimeHold = dur;
}

/*         MOVEMENT         */
void Character::moveRight(Block&block, Character& player) {
	if (block.checkIfPlayerIsFlying(player) && !jumped && !falling) {
		velocity[1] = 0;
		velocity[0] = 0;
		falling = true;
	}

	temp1 = 10 * keyTimeHold*run_boost; //boosting player's speed
	temp2 = coordinateX + temp1;
	velocity[0] = temp1*0.5;
	coordinateX = temp2;
	start = std::clock();
}

void Character::moveLeft(Block&block, Character& player) {
	if (block.checkIfPlayerIsFlying(player) && !jumped && !falling) {
		velocity[1] = 0;
		velocity[0] = 0;
		falling = true;
	}

	temp1 = -10 * keyTimeHold*run_boost; // boosting player's speed
	temp2 = coordinateX + temp1;
	velocity[0] = temp1*0.5;
	coordinateX = temp2;
	start = std::clock();
}

void Character::startJump() {
	if (onGround){
		velocity[1] = -11.0;
		onGround = false;
		jumped = true;
	}
}

void Character::updateJump(Block& block, Character& player) {
	if (!onGround || falling) {
		if (velocity[1] < 0)
			velocity[1] += up_gravity;
		else
			velocity[1] += falling_gravity;
		coordinateY += velocity[1];
		coordinateX += velocity[0];
		if (velocity[1] >= 0) {
			block.collidingWithPlayer(player);
		}
	}

	if (coordinateY > 460){
		coordinateY = 460;
		velocity[0] = 0.0;
		velocity[1] = 0.0;
		onGround = true;
		jumped = false;
		falling = false;
	}

	if ((coordinateX + bitmapWidth >= START_OF_RIGHT_WALL && coordinateX <= WALL_WIDTH + START_OF_RIGHT_WALL) || (coordinateX + bitmapWidth >= START_OF_LEFT_WALL && coordinateX <= START_OF_LEFT_WALL + WALL_WIDTH)){
	velocity[0] *= -1;
	bound = true;
	if (movingInDirection == 1)
		movingInDirection = 2;
	else if (movingInDirection == 2)
		movingInDirection = 1;
	}
}

void Character::updateScore(Character&player, int i) {
	if (player.totalScore / block_point <= i)
		player.totalScore = i * block_point + bonusPoints;
}

void Character::drawScore(float* CameraPosition) {
	al_draw_textf(font, al_map_rgb(255, 128, 0), 130+CameraPosition[0], 500+CameraPosition[1], ALLEGRO_ALIGN_CENTRE, "Score: %d", totalScore);
}

void Character::drawCharacter(int direction, float* CameraPosition) {
	switch (direction) {
	case 1:
		al_draw_bitmap(player_left, coordinateX, coordinateY, 0);
		break;
	case 2:
		al_draw_bitmap(player_right, coordinateX, coordinateY, 0);
		break;
	}
	drawScore(CameraPosition);
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

void Character::addBonusPoints(int num) {
	bonusPoints += num;
}