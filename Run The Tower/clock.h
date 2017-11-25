#pragma once

#include <ctime>
#include <math.h>
#include <allegro5\allegro_primitives.h>

static int MIDDLE_X_CLOCK = 50;
static int MIDDLE_Y_CLOCK = 75;
static int RADIUS_OF_CLOCK = 50;
static double M_PI = 3.14159265358979323846;
static float constCameraBoost = 1.0; // Camera's bonus speed after passing 30 seconds

class MyClock {
	friend class Camera;
	bool firstTick;
	const int RGB_clock[3] = { 0,0,0 }; // clock line constants
	int myTime;
	int degree;
	int oldTime;
	float cameraBoost;
	double xC, yC;
	double currentDegree;
	
	clock_t my_clock;
	ALLEGRO_BITMAP *clockbmp;

public:
	MyClock();
	~MyClock();
	void Tick(float* CameraPosition);
	void Draw(float* CameraPosition);
	void Update(float* CameraPosition);
	void flipDisplay();
	void Init(clock_t clock);
};
