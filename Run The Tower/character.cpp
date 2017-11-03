#include "character.h"

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
	setWidth(al_get_bitmap_width(player_left));
	setHeight(al_get_bitmap_height(player_left));
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
		vel[1] = -11.0;
		onGround = false;
	}
}
void character::endJump()
{
	if (vel[1] < -11.0)
		vel[1] = -11.0;
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
void character::Draw(int direction) {
	switch (direction) {
	case 1:
		al_draw_bitmap(player_left, x, y, 0);
		break;
	case 2:
		al_draw_bitmap(player_right, x, y, 0);
		break;
	}
	al_draw_textf(font, al_map_rgb(255, 128, 0), 130, 500, ALLEGRO_ALIGN_CENTRE, "Score: %d", score);
	flipDisplay();
}
void character::moveRight() {
	temp1 = 10 * duration*run_boost;
	temp2 = x + temp1;
	vel[0] = temp1*0.5;
	x = temp2;
	start = std::clock();
}
void character::moveLeft() {
	temp1 = -10 * duration*run_boost;
	temp2 = x + temp1;
	vel[0] = temp1*0.5;
	x = temp2;
	start = std::clock();
}

void character::setDuration(double dur) {
	duration = dur;
}
void character::flipDisplay() {
	al_flip_display();
}
bool character::isColliding(int pos_x1, int width_x1, int pos_x2, int width_x2) {
	if (pos_x1 + width_x1 >= pos_x2 && pos_x1 <= pos_x2 + width_x2)
		return true;
	else return false;
}