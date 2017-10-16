#pragma once

class character {
	int x;
	int y;

	int width;
	int height;
public:
	character(int position_x, int position_y) : x(position_x), y(position_y) {
	}
	int get_x();
	int get_y();
	int get_width();
	int get_height();
	void set_x(int position_x);
	void set_y(int position_y);
	void set_width(int pwidth);
	void set_height(int pheight);
};