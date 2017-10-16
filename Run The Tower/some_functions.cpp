#pragma once

bool collision(int pos_x1, int width_x1, int pos_x2, int width_x2, int pos_y1, int height_y1, int pos_y2, int height_y2) {
	if (pos_x1 + width_x1 >= pos_x2 && pos_x1 <= pos_x2 + width_x2 && pos_y1 + height_y1 >= pos_y2 && pos_y1 <= pos_y2 + height_y2)
		return true;
	else return false;
}