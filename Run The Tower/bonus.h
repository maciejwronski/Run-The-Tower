#pragma once
#include "Allegro.h"
#include "allegro5\allegro_primitives.h"
#include "block.h"
#include "character.h"

static const int bonusEveryXBlock = 5;
static const int bonusNumber = MAX_BLOCKS / bonusEveryXBlock;

static const int pointsForCircle = 1;
static const int pointsForRectangle = 2;
static const int pointsForTriangle = 3;

static const float constansToDrawBonus = 20;

class Bonus {
	friend class Block;
	friend class Character;
	float positionX[bonusNumber];
	float positionY[bonusNumber];
	int bonusType[bonusNumber]; // 0 - circle, 1 - rectangle, 2 - triangle
	bool given[bonusNumber];

public:
	Bonus();
	~Bonus();

	void drawBonus();
	void createBonus(Block& block);
	void admitBonus(Character& character);
};