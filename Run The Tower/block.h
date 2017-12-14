#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <ctime>
#include "character.h"


static int MAX_RANDOM_X_SIZE = 250;
static int MIN_RANDOM_X_SIZE = 100;
static float block_height = 31;
static const int MAX_BLOCKS = 1000;

class Block {
	friend class Character;
	friend class Bonus;
	float coordinateX[MAX_BLOCKS];
	float coordinateY[MAX_BLOCKS];
	float width[MAX_BLOCKS];

	ALLEGRO_BITMAP *floorbmp;
public:
	Block();
	~Block();
	float* getCoordinateX();
	float* getCoordinateY();
	float* getWidth();
	bool checkIfPlayerIsFlying(Character& player);
	void createBlocks();
	void drawBlocks();
	void collidingWithPlayer(Character& player);
};

