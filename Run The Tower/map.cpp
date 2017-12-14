#include "map.h"
#include <iostream>

Map::Map() {
	srand(time(NULL));
	brickbmp = al_load_bitmap("game_images/brick.jpg");
	floorbmp = al_load_bitmap("game_images/floor.jpg");
}

Map::~Map() {
	al_destroy_bitmap(brickbmp);
	al_destroy_bitmap(floorbmp);
}

bool Map::wallsCollidingWithPlayer(Character& player, int pos_x2, int width_x2) {
	if (player.getPositionX() + player.getWidth() >= pos_x2 && player.getPositionX() <= pos_x2 + width_x2) {
		return true;
	}
	else return false;
}

void Map::walls(float* CameraPosition) {
	al_draw_bitmap(brickbmp, START_OF_LEFT_WALL + CameraPosition[0], CameraPosition[1], 0);
	al_draw_bitmap(brickbmp, START_OF_RIGHT_WALL + CameraPosition[0], CameraPosition[1], 0);
	al_draw_bitmap(floorbmp, START_FLOOR_X, START_FLOOR_Y, 0);
}

void Map::background() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
}

void Map::draw(float* CameraPosition) {
	background();
	walls(CameraPosition);
}