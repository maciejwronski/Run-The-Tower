#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include "character.h"

extern int START_OF_LEFT_WALL;// = 0; // start of left wall
extern int START_OF_RIGHT_WALL;// = 718; // where right wall starts
extern int WALL_WIDTH;// = 82; // width of wall

extern int START_FLOOR_X;// = 82; // where start-floor starts x axis
extern int START_FLOOR_Y;// = 530; // where start-floor starts y axis

class map {
	friend class character;
	ALLEGRO_BITMAP *brickbmp = al_load_bitmap("game_images/brick.jpg");
	ALLEGRO_BITMAP *floorbmp = al_load_bitmap("game_images/floor.jpg");
public:

	void Init();
	void Background();
	void Walls(float* CameraPosition);
	void Draw(float* CameraPosition);
	bool WallsCollidingWithPlayer(character& player, int pos_x2, int width_x2);

};