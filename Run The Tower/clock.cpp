#include "clock.h"

MyClock::MyClock() {
	firstTick = true;
	degree = 0;
	newTime = -1;
	currentDegree = 0;
	cameraBoost = 2;
	clockbmp = al_load_bitmap("game_images/clock.png");
}

MyClock::~MyClock() {
	al_destroy_bitmap(clockbmp);
}

void MyClock::init(clock_t clock) {
	my_clock = clock;
}

void MyClock::tick(float* CameraPosition) {
	currentTime = static_cast<int>((std::clock() - my_clock) / static_cast<double>(CLOCKS_PER_SEC));
	if (firstTick) {
		newTime = currentTime;
		firstTick = false;
	}
	if (currentTime != newTime) {
		newTime = currentTime;
		degree += 12;
		if (degree == 360) {
			degree = 0;
			cameraBoost += constCameraBoost;
		}
	}

	currentDegree = radToDeg(degree);
	xC = static_cast<double>(50 * sin(currentDegree));
	yC = static_cast<double>(50 * cos(currentDegree));
	al_draw_line(50 + CameraPosition[0], 55 + CameraPosition[1], CameraPosition[0] + 50 + xC, 75 - yC + CameraPosition[1], al_map_rgb(RGB_clock[0], RGB_clock[1], RGB_clock[2]), 5);
}

void MyClock::draw(float* CameraPosition) {
	al_draw_bitmap(clockbmp, CameraPosition[0], CameraPosition[1], 0);
}

void MyClock::update(float* CameraPosition) {
	draw(CameraPosition);
	tick(CameraPosition);
	flipDisplay();
}

void MyClock::flipDisplay() {
	al_flip_display();
}

float MyClock::radToDeg(int deg) {
	return deg*M_PI / 180;
}