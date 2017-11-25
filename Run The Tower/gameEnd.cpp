#include "gameEnd.h"

GameEnd::GameEnd() {
	font = al_load_font("fonts/times.ttf", 32, 0);
}
GameEnd::~GameEnd(){
	al_destroy_font(font);
}
void GameEnd::drawScore(Character& character) {
	al_flip_display();
	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_textf(font, al_map_rgb(255,255,255), 100 ,0, 0, "Koniec gry! Twoj wynik to: %d", character.getScore());
	al_flip_display();
	waitSeconds(10);
}
void GameEnd::waitSeconds(int num) {
	al_rest(num);
}