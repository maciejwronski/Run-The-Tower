#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <ctime>
static int START_WALL_X = 0; // start of left wall
static int END_WALL_X = 718; // where right wall starts
static int WALL_WIDTH = 82; // width of wall

static int START_FLOOR_X = 82; // where start-floor starts x axis
static int START_FLOOR_Y = 530; // where start-floor starts y axis

static int MAX_RANDOM_X_SIZE = 250;
static int MIN_RANDOM_X_SIZE = 100;
static const int MAX_BLOCKS = 2000;

class map {
	ALLEGRO_BITMAP *brickbmp = al_load_bitmap("game_images/brick.jpg");
	ALLEGRO_BITMAP *floorbmp = al_load_bitmap("game_images/floor.jpg");
	ALLEGRO_BITMAP *blockbmp = al_load_bitmap("game_images/first.png");
	
	float tab_axis[MAX_BLOCKS][2] = { 0 };
	short tab_width[MAX_BLOCKS] = { 0 };
public:

	void Init();
	void FirstBlocks();
	void DrawFirstBlocks();
	void Walls();
	void Background();
	void Update();
	void flipDisplay();

};