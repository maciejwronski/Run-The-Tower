#include "clock.h"

MyClock::MyClock() {
	firstTick = true;
	degree = 0;
	oldTime = 34;
	currentDegree = 0;
	cameraBoost = 2;
	clockbmp = al_load_bitmap("game_images/clock.png");
}
MyClock::~MyClock() {
	al_destroy_bitmap(clockbmp);
}

void MyClock::Init(clock_t clock) {
	my_clock = clock;
}
void MyClock::Tick(float* CameraPosition) {
	myTime = (int)(std::clock() - my_clock) / (double)CLOCKS_PER_SEC;
	if (firstTick) {
		oldTime = myTime;
		firstTick = false;
	}
	if (myTime != oldTime) {
		oldTime = myTime;
		degree += 12;
		if (degree == 360) {
			degree = 0;
			cameraBoost += constCameraBoost;
		}
	}

	currentDegree = degree * M_PI / 180;
	xC = (double)(50 * sin(currentDegree));
	yC = (double)(50 * cos(currentDegree));
	al_draw_line(50 + CameraPosition[0], 55 + CameraPosition[1], CameraPosition[0] + 50 + xC, 75 - yC + CameraPosition[1], al_map_rgb(RGB_clock[0], RGB_clock[1], RGB_clock[2]), 5);
}
void MyClock::Draw(float* CameraPosition) {
	al_draw_bitmap(clockbmp, CameraPosition[0], CameraPosition[1], 0);
}
void MyClock::Update(float* CameraPosition) {
	Draw(CameraPosition);
	Tick(CameraPosition);
	flipDisplay();
}
void MyClock::flipDisplay() {
	al_flip_display();
}