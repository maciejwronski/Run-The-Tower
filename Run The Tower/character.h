#pragma once

class character {
	int x, y;
	int dx, dy;
	bool mayJump;
	bool onGround;
	int width;
	int height;
public:
	character(int position_x, int position_y) : x(position_x), y(position_y) {
	}
	int get_x();
	int get_y();
	int get_width();
	int get_height();
	int get_dx();
	int get_dy();
	int can_jump();
	int is_on_ground();
	void set_x(int position_x);
	void set_y(int position_y);
	void set_dx(int dxx);
	void set_dy(int dyy);
	void set_width(int pwidth);
	void set_height(int pheight);
	void set_jump(bool can_jump);
	void set_ground(bool on_ground);

};