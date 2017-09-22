#pragma once

#include "character.h"

int character::get_x() {
	return x;
}
int character::get_y() {
	return y;
}
void character::set_x(int position_x) {
	x = position_x;
}
void character::set_y(int position_y) {
	y = position_y;
}