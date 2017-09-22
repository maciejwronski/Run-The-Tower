#pragma once

class character {
	int x;
	int y;

public:
	character();
	character(int position_x, int position_y) : x(position_x), y(position_y) {
	}
	int get_x();
	int get_y();
	void set_x(int x);
	void set_y(int y);

};