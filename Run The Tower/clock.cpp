#include "clock.h"

myClock::myClock() {

}
myClock::~myClock() {

}

void myClock::Init(clock_t clock) {
	my_clock = clock;
	camera_boost = 2;
	clockbmp = al_load_bitmap("game_images/clock.png");
}
void myClock::Tick(float* CameraPosition) {
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
			camera_boost += constCameraBoost;
		}
	}

	current_degree = degree * M_PI / 180;
	x_c = (double)(50 * sin(current_degree));
	y_c = (double)(50 * cos(current_degree));
	al_draw_line(50 + CameraPosition[0], 55 + CameraPosition[1], CameraPosition[0] + 50 + x_c, 75 - y_c + CameraPosition[1], al_map_rgb(RGB_clock[0], RGB_clock[1], RGB_clock[2]), 5);
}
void myClock::Draw(float* CameraPosition) {
	al_draw_bitmap(clockbmp, CameraPosition[0], CameraPosition[1], 0);
}
void myClock::Update(float* CameraPosition) {
	Draw(CameraPosition);
	Tick(CameraPosition);
	flipDisplay();
}
void myClock::flipDisplay() {
	al_flip_display();
}