#pragma once

#include "character.h"

int character::get_x() {
	return x;
}
int character::get_y() {
	return y;
}
int character::get_width() {
	return width;
}
int character::get_height() {
	return height;
}
int character::get_dx() {
	return dx;
}
int character::get_dy() {
	return dy;
}
int character::can_jump() {
	return mayJump;
}
int character::is_on_ground() {
	return onGround;
}
void character::set_width(int pwidth) {
	width = pwidth;
}
void character::set_height(int pheight) {
	height = pheight;
}

void character::set_x(int position_x) {
	x = position_x;
}
void character::set_y(int position_y) {
	y = position_y;
}

void character::set_dx(int dxx) {
	dx = dxx;
}
void character::set_dy(int dyy) {
	dy = dyy;
}
void character::set_jump(bool can_jump) {
	mayJump = can_jump;
}
void character::set_ground(bool on_ground) {
	onGround = on_ground;
}