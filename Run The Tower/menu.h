#pragma once

#include "allegro5\allegro.h"
#include "allegro5\allegro_font.h"

class Menu {
	int whichMenu; // 0 - EXIT 1 - Main, 2 - Instructions, 3 - Options, 4 - inGame
	int mainMenuPick;
	bool inInstructions;
	bool inOptions;

	ALLEGRO_BITMAP *startbmp;
	ALLEGRO_BITMAP *instructionsbmp;
	ALLEGRO_BITMAP *optionsbmp;
	ALLEGRO_BITMAP *exitbmp;
	ALLEGRO_BITMAP *menusquarebmp;
	ALLEGRO_BITMAP *logobmp;
	ALLEGRO_FONT *font;
public:
	Menu();
	~Menu();
	void drawMainMenu();
	void drawInstructions();
	void drawOptions();
	void setMainMenuPick(int numb);
	void setMenu(int numb);
	int getMenu();
	int getMainMenuPick();
};