#pragma once
#include "allegro5\allegro.h"
#include "allegro5\allegro_font.h"
#include "character.h"

class GameEnd {
	ALLEGRO_FONT *font;

public:
	GameEnd();
	~GameEnd();
	void waitSeconds(int num);
	void drawScore(Character& character);
};