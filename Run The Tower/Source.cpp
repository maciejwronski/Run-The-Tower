#pragma once

#include "includes.h"
#include "Allegro.h"

map Map;
character player;
myClock gameClock;
menu MyMenu;
Allegro allegro;
block Block;
camera Camera;

ALLEGRO_TRANSFORM cameratrans;

void menuLoop() {
	if (MyMenu.getMenu() == 1) {
		MyMenu.drawMainMenu();
	}
	else if (MyMenu.getMenu() == 2) {
		MyMenu.drawInstructions();
	}
	else if (MyMenu.getMenu() == 3) {
		MyMenu.drawOptions();
	}
	ALLEGRO_EVENT ev;
	al_wait_for_event(menu_event_queue, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP: keys[UP] = true; if (MyMenu.getMenu() == 1) if (MyMenu.getMainMenuPick() - 50 > 0) MyMenu.setMainMenuPick(-50);  break; // adding values to position of bmp in range of 25/175
		case ALLEGRO_KEY_DOWN: keys[DOWN] = true; if (MyMenu.getMenu() == 1) if (MyMenu.getMainMenuPick() + 50 <= 175) MyMenu.setMainMenuPick(50); break;
		case ALLEGRO_KEY_RIGHT: keys[RIGHT] = true;  break;
		case ALLEGRO_KEY_LEFT: keys[LEFT] = true;  break;
		case ALLEGRO_KEY_ENTER:  break;
		case ALLEGRO_KEY_ESCAPE: if (MyMenu.getMenu() == 2) MyMenu.setMenu(1); if (MyMenu.getMenu() == 3) MyMenu.setMenu(1); al_flip_display();  break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP: keys[UP] = false;  break;
		case ALLEGRO_KEY_DOWN: keys[DOWN] = false;  break;
		case ALLEGRO_KEY_RIGHT: keys[RIGHT] = false; break;
		case ALLEGRO_KEY_LEFT: keys[LEFT] = false; break;
		case ALLEGRO_KEY_ENTER:
			if (MyMenu.getMenu() == 1) {
				switch (MyMenu.getMainMenuPick()) {
				case 25: {
					keys[LEFT] = keys[RIGHT] = false; // In case player is holding key, to prevent from megaboost
					allegro.changeEvents(); // Menu event to game event
					MyMenu.setMenu(4); // Starts game
					Map.Init(); // Inits map
					player.Init(); // Inits player
					Block.Init();
					gameClock.Init(std::clock()); // Inits clock
					break;
				}
				case 75: MyMenu.setMenu(2); break;
				case 125: MyMenu.setMenu(3); break;
				case 175: MyMenu.setMenu(0); break;
				}
			}
			break;
		case ALLEGRO_KEY_ESCAPE: break;
		}
	}
	al_flip_display();
}
void gameLoop() {
	ALLEGRO_EVENT ev1;
	al_wait_for_event(game_event_queue, &ev1);
	if (ev1.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev1.keyboard.keycode) {
		case ALLEGRO_KEY_RIGHT: keys[RIGHT] = true; start = std::clock(); player.setDirection(2);  break;
		case ALLEGRO_KEY_LEFT: keys[LEFT] = true;  start = std::clock(); player.setDirection(1); break;
		case ALLEGRO_KEY_SPACE: keys[SPACE] = true;  player.startJump(Map, player); break;
		case ALLEGRO_KEY_UP: keys[UP] = true; player.startJump( Map, player); break;

		}
	}
	else if (ev1.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch (ev1.keyboard.keycode) {
		case ALLEGRO_KEY_RIGHT: keys[RIGHT] = false; player.setDuration(0); break;
		case ALLEGRO_KEY_LEFT: keys[LEFT] = false; player.setDuration(0); break;
		case ALLEGRO_KEY_SPACE: keys[SPACE] = false; break;
		case ALLEGRO_KEY_UP: keys[UP] = false; break;
		}
	}
	else if (ev1.type == ALLEGRO_EVENT_TIMER)
	{
		Map.Draw(CameraPosition);
		Block.DrawBlocks();
		gameClock.Update(CameraPosition);
		player.DrawCharacter(player.getDirection(), CameraPosition);
		player.updateJump(Block, player);
		Camera.Update(player, gameClock, CameraPosition);
		Camera.Translation(cameratrans, CameraPosition);
		if (keys[RIGHT] || keys[LEFT]) {
			temp = ((std::clock() - start) / (double)CLOCKS_PER_SEC);
			player.setDuration(temp);
		}
		if (keys[RIGHT]) {
			if (!Map.WallsCollidingWithPlayer(player, START_OF_RIGHT_WALL, brick_width)) {
				player.moveRight(Block, player);
			}
		}
		else if (keys[LEFT]) {
			if (!Map.WallsCollidingWithPlayer(player, START_OF_LEFT_WALL, brick_width)) {
				player.moveLeft(Block, player);
			}
		}
		else if (keys[SPACE] || keys[UP]) {

		}
	}
}

int main(void) {
	allegro.Conditions();
	allegro.InitAddons();
	allegro.registerQueueEvents();
	MyMenu.Init();
	while (MyMenu.getMenu() != 0 && MyMenu.getMenu() != 4) {
		menuLoop();
	}
	while (MyMenu.getMenu() == 4) {
		gameLoop();
	}
	allegro.Destroy();
	return 0;
}