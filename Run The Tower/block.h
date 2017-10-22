#pragma once

class block {
	int x, y;
	int width, height;

	int get_x();
	int get_y();
	int get_width();
	int get_height();

	void set_x(int position_x);
	void set_y(int position_y);
	void set_width(int pwidth);
	void set_height(int pheight);
	void create(int sx, int sy, int swidth, int sheight);
};