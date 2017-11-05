#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <ctime>
#include "map.h"
#include "character.h"

static int MAX_RANDOM_X_SIZE = 250;
static int MIN_RANDOM_X_SIZE = 100;
static int block_height = 31;
static const int MAX_BLOCKS = 3;

class block {
	friend class character;
	ALLEGRO_BITMAP *floorbmp = al_load_bitmap("game_images/floor.jpg");
	float coordinate[MAX_BLOCKS][2] = { 0 };
	unsigned short width[MAX_BLOCKS] = { 0 };
public:
	void Init();
	void CreateBlocks();
	void DrawBlocks();
	void CollidingWithPlayer(character& player);
};