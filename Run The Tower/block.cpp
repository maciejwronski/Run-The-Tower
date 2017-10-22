#include "block.h"
#pragma once

int block::get_x() {
	return x;
}
int block::get_y() {
	return y;
}
int block::get_width() {
	return width;
}
int block::get_height() {
	return height;
}

void block::set_x(int position_x) {
	x = position_x;
}
void block::set_y(int position_y) {
	y = position_y;
}
void block::set_width(int pwidth) {
	width = pwidth;
}
void block::set_height(int pheight) {
	height = pheight;
}

void block::create(int sx, int sy, int swidth, int sheight) {
	x = sx;
	y = sy;
	width = swidth;
	height = sheight;

}