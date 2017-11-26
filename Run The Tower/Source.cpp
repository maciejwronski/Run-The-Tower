#pragma once

#include "includes.h"
#include "Allegro.h"

Allegro allegro;
Character character;
Map map;
MyClock myClock;
Menu menu;
Block block;
Camera camera;
ALLEGRO_TRANSFORM cameratrans;
Bonus bonus;

void menuLoop() {
	if (menu.getMenu() == 1) {
		menu.drawMainMenu();
	}
	else if (menu.getMenu() == 2) {
		menu.drawInstructions();
	}
	else if (menu.getMenu() == 3) {
		menu.drawOptions();
	}
	ALLEGRO_EVENT ev;
	al_wait_for_event(menu_event_queue, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP: keys[UP] = true; if (menu.getMenu() == 1) if (menu.getMainMenuPick() - 50 > 0)menu.setMainMenuPick(-50);  break; // adding values to position of bmp in range of 25/175
		case ALLEGRO_KEY_DOWN: keys[DOWN] = true; if (menu.getMenu() == 1) if (menu.getMainMenuPick() + 50 <= 175) menu.setMainMenuPick(50); break;
		case ALLEGRO_KEY_RIGHT: keys[RIGHT] = true;  break;
		case ALLEGRO_KEY_LEFT: keys[LEFT] = true;  break;
		case ALLEGRO_KEY_ENTER:  break;
		case ALLEGRO_KEY_ESCAPE: if (menu.getMenu() == 2) menu.setMenu(1); if (menu.getMenu() == 3) menu.setMenu(1); al_flip_display();  break;
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
			if (menu.getMenu() == 1) {
				switch (menu.getMainMenuPick()) {
				case 25: {
					keys[LEFT] = keys[RIGHT] = false; // In case player is holding key, to prevent from megaboost
					allegro.changeEvents(); // Menu event to game event
					menu.setMenu(4); // Starts game
					myClock.Init(std::clock()); // Inits clock
					bonus.createBonus(block);
					break;
				}
				case 75: menu.setMenu(2); break;
				case 125: menu.setMenu(3); break;
				case 175: menu.setMenu(0); break;
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
		case ALLEGRO_KEY_RIGHT: keys[RIGHT] = true; start = std::clock(); character.setDirection(2);  break;
		case ALLEGRO_KEY_LEFT: keys[LEFT] = true;  start = std::clock(); character.setDirection(1); break;
		case ALLEGRO_KEY_SPACE: keys[SPACE] = true;  character.startJump(); break;
		case ALLEGRO_KEY_UP: keys[UP] = true; character.startJump(); break;

		}
	}
	else if (ev1.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch (ev1.keyboard.keycode) {
		case ALLEGRO_KEY_RIGHT: keys[RIGHT] = false; character.setDuration(0); break;
		case ALLEGRO_KEY_LEFT: keys[LEFT] = false; character.setDuration(0); break;
		case ALLEGRO_KEY_SPACE: keys[SPACE] = false; break;
		case ALLEGRO_KEY_UP: keys[UP] = false; break;
		}
	}
	else if (ev1.type == ALLEGRO_EVENT_TIMER)
	{
		map.Draw(camera.GetCameraPos());
		block.DrawBlocks();
		character.DrawCharacter(character.getDirection(), camera.GetCameraPos());
		bonus.drawBonus();
		bonus.admitBonus(character);
		character.updateJump(block, character);
		if(camera.CameraShouldStart(map, character)){
			camera.Update(character, myClock, camera.GetCameraPos());
			camera.Translation(cameratrans, camera.GetCameraPos());
			myClock.Update(camera.GetCameraPos());
			if (camera.playerHasFallenDown(map, character)) {
				menu.setMenu(0);
			}
		}
		if (keys[RIGHT] || keys[LEFT]) {
			temp = ((std::clock() - start) / (double)CLOCKS_PER_SEC);
			character.setDuration(temp);
		}
		if (keys[RIGHT]) {
			if (!map.WallsCollidingWithPlayer(character, START_OF_RIGHT_WALL, WALL_WIDTH)) {
				character.moveRight(block, character);
			}
		}
		else if (keys[LEFT]) {
			if (!map.WallsCollidingWithPlayer(character, START_OF_LEFT_WALL, WALL_WIDTH)) {
				character.moveLeft(block, character);
			}
		}
	}
}

int main(void) {
	while (menu.getMenu() != 0 && menu.getMenu() != 4) {
		menuLoop();
	}
	while (menu.getMenu() == 4) {
		gameLoop();
	}
	return 0;
}