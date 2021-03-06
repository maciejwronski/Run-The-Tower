#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "character.h"
#include "menu.h"

static const int START_OF_LEFT_WALL = 0;// = 0; // start of left wall
static const int START_OF_RIGHT_WALL = 718;// = 718; // where right wall starts
static const int WALL_WIDTH = 82;// = 82; // width of wall

static const int START_FLOOR_X = 82;// = 82; // where start-floor starts x axis
static const int START_FLOOR_Y = 530;// = 530; // where start-floor starts y axis

class Map {
	friend class Character;
	friend class Camera;
	friend class Menu;
	bool mapFalling = false;

	ALLEGRO_BITMAP *brickbmp = al_load_bitmap("game_images/brick.jpg");
	ALLEGRO_BITMAP *floorbmp = al_load_bitmap("game_images/floor.jpg");
public:

	Map();
	~Map();
	void background();
	void walls(float* CameraPosition);
	void draw(float* CameraPosition);
	bool wallsCollidingWithPlayer(Character& player, int pos_x2, int width_x2);

};