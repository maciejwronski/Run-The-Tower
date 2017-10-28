#include "clock.h"

myClock::myClock() {

}
myClock::~myClock() {

}

void myClock::Init(clock_t clock) {
	my_clock = clock;
	clockbmp = al_load_bitmap("game_images/clock.png");
}
void myClock::Tick() {
	my_time = (int)(std::clock() - my_clock) / (double)CLOCKS_PER_SEC;
	if (first_tick) {
		old_time = my_time;
		first_tick = false;
	}
	if (my_time != old_time) {
		old_time = my_time;
		degree += 12;
		if (degree == 360) {
			degree = 0;
		}
	}

	current_degree = degree * M_PI / 180;
	x_c = (double)(50 * sin(current_degree));
	y_c = (double)(50 * cos(current_degree));
	al_draw_line(50, 75, 50 + x_c, 75 - y_c, al_map_rgb(RGB_clock[0], RGB_clock[1], RGB_clock[2]), 5);
}
void myClock::Draw() {
	al_draw_bitmap(clockbmp, 0, 20, 0);
}