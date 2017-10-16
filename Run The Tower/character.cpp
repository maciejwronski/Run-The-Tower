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