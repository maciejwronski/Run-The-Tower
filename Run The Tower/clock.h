#pragma once

#include <ctime>
#include <math.h>
#include <allegro5\allegro_primitives.h>

static const int MIDDLE_X_CLOCK = 50;
static const int MIDDLE_Y_CLOCK = 75;
static const int RADIUS_OF_CLOCK = 50;
static const double M_PI = 3.14159265358979323846;
static const float constCameraBoost = 1.0; // Camera's bonus speed after passing 30 seconds

class MyClock {
	friend class Camera;

	bool firstTick;

	const int RGB_clock[3] = { 0,0,0 }; // clock line constants

	int currentTime, newTime, degree;

	float cameraBoost;
	double xC, yC;
	double currentDegree;

	clock_t my_clock;
	ALLEGRO_BITMAP *clockbmp;

	void tick(float* CameraPosition);
	void draw(float* CameraPosition);
	void flipDisplay();

	float radToDeg(int degree);

public:
	MyClock();
	~MyClock();
	void update(float* CameraPosition);
	void init(clock_t clock);
};