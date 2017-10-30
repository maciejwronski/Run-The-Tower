#include "menu.h"

void menu::Init() {
	startbmp = al_load_bitmap("menu_images/start.png");
	instructionsbmp = al_load_bitmap("menu_images/instructions.png");
	optionsbmp = al_load_bitmap("menu_images/options.png");
	exitbmp = al_load_bitmap("menu_images/exit.png");
	menusquarebmp = al_load_bitmap("menu_images/choosen.png");
	logobmp = al_load_bitmap("menu_images/logo.png");
	font = al_load_font("fonts/times.ttf", 24, 0);
}
void menu::drawMainMenu() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(logobmp, 0, 20, 0);
	al_draw_bitmap(startbmp, 50, 300, 0);
	al_draw_bitmap(instructionsbmp, 50, 350, 0);
	al_draw_bitmap(optionsbmp, 50, 400, 0);
	al_draw_bitmap(exitbmp, 50, 450, 0);
	al_draw_bitmap(menusquarebmp, 20, 300 + mainMenuPick, 0);
}
void menu::drawInstructions() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "Tutaj jakies instrukcje mordeczko!");
}
void menu::drawOptions() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "Tutaj jakies opcje mordeczko!");
}

void menu::setMenu(int numb) {
	whichMenu = numb;
}

int menu::getMenu() {
	return whichMenu;
}

void menu::setMainMenuPick(int numb) {
	mainMenuPick += numb;
}

int menu::getMainMenuPick() {
	return mainMenuPick;
}