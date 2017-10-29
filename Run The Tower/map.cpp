#include "map.h"

void map::Init() {
	brickbmp = al_load_bitmap("game_images/brick.jpg");
	floorbmp = al_load_bitmap("game_images/floor.jpg");
}
void map::Walls() {
	al_draw_bitmap(brickbmp, START_WALL_X, 0, 0);
	al_draw_bitmap(brickbmp, END_WALL_X, 0, 0);
	al_draw_bitmap(floorbmp, START_FLOOR_X, START_FLOOR_Y, 0);
}

void map::Background() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
}
void map::flipDisplay() {
	al_flip_display();
}
void map::Update() {
	Background();
	Walls();
	flipDisplay();
}