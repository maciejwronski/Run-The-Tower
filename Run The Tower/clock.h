#pragma once

#include <ctime>
#include <math.h>
#include <allegro5\allegro_primitives.h>

static int MIDDLE_X_CLOCK = 50;
static int MIDDLE_Y_CLOCK = 75;
static int RADIUS_OF_CLOCK = 50;
static double M_PI = 3.14159265358979323846;


class myClock {

	int my_time;
	int old_time = 34;
	bool first_tick = true;
	const int RGB_clock[3] = { 0,0,0 }; // clock line constants
	double x_c, y_c;
	double current_degree = 0;
	int degree = 0;
	
	clock_t my_clock;
	ALLEGRO_BITMAP *clockbmp = NULL;

public:
	myClock();
	~myClock();
	void Tick();
	void drawClock();
	void Update();
	void flipDisplay();
	void Init(clock_t clock);
};
