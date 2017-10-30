#pragma once

#include "allegro5\allegro.h"
#include "allegro5\allegro_font.h"

class menu {
	int whichMenu = 1; // 0 - EXIT 1 - Main, 2 - Instructions, 3 - Options, 4 - inGame
	int mainMenuPick = 25;
	bool inInstructions;
	bool inOptions;

	ALLEGRO_BITMAP *startbmp = NULL;
	ALLEGRO_BITMAP *instructionsbmp = NULL;
	ALLEGRO_BITMAP *optionsbmp = NULL;
	ALLEGRO_BITMAP *exitbmp = NULL;
	ALLEGRO_BITMAP *menusquarebmp = NULL;
	ALLEGRO_BITMAP *logobmp = NULL;
	ALLEGRO_FONT *font = NULL;
public:
	void Init();
	void drawMainMenu();
	void drawInstructions();
	void drawOptions();

	void setMenu(int numb);
	int getMenu();

	void setMainMenuPick(int numb);
	int getMainMenuPick();
};