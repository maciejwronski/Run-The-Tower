#include "menu.h"

Menu::Menu() {
	whichMenu = 1;
	mainMenuPick = 25;
	startbmp = al_load_bitmap("menu_images/start.png");
	instructionsbmp = al_load_bitmap("menu_images/instructions.png");
	optionsbmp = al_load_bitmap("menu_images/options.png");
	exitbmp = al_load_bitmap("menu_images/exit.png");
	menusquarebmp = al_load_bitmap("menu_images/choosen.png");
	logobmp = al_load_bitmap("menu_images/logo.png");
	font = al_load_font("fonts/times.ttf", 24, 0);
}

Menu::~Menu() {
	al_destroy_bitmap(startbmp);
	al_destroy_bitmap(instructionsbmp);
	al_destroy_bitmap(optionsbmp);
	al_destroy_bitmap(exitbmp);
	al_destroy_bitmap(menusquarebmp);
	al_destroy_bitmap(logobmp);
	al_destroy_font(font);
}

void Menu::drawMainMenu() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(logobmp, 0, 20, 0);
	al_draw_bitmap(startbmp, 50, 300, 0);
	al_draw_bitmap(instructionsbmp, 50, 350, 0);
	al_draw_bitmap(optionsbmp, 50, 400, 0);
	al_draw_bitmap(exitbmp, 50, 450, 0);
	al_draw_bitmap(menusquarebmp, 20, 300 + mainMenuPick, 0);
}

void Menu::drawInstructions() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "Instructions");
}

void Menu::drawOptions() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_map_rgb(255, 255, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "Options");
}

void Menu::setMenu(int numb) {
	whichMenu = numb;
}

void Menu::setMainMenuPick(int numb) {
	mainMenuPick += numb;
}

int Menu::getMainMenuPick() {
	return mainMenuPick;
}

int Menu::getMenu() {
	return whichMenu;
}
