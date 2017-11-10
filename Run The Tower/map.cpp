#include "map.h"
#include <iostream>

int START_OF_LEFT_WALL = 0; // start of left wall
int START_OF_RIGHT_WALL = 718; // where right wall starts
int WALL_WIDTH = 82; // width of wall

int START_FLOOR_X = 82; // where start-floor starts x axis
int START_FLOOR_Y = 530; // where start-floor starts y axis

void map::Init() {
	srand(time(NULL));
	brickbmp = al_load_bitmap("game_images/brick.jpg");
	floorbmp = al_load_bitmap("game_images/floor.jpg");
}
bool map::WallsCollidingWithPlayer(character& player, int pos_x2, int width_x2) {
	if (player.x + player.width >= pos_x2 && player.x <= pos_x2 + width_x2) {
		return true;
	}
	else return false;
}
void map::Walls(float* CameraPosition) {
	al_draw_bitmap(brickbmp, START_OF_LEFT_WALL + CameraPosition[0], CameraPosition[1], 0);
	al_draw_bitmap(brickbmp, START_OF_RIGHT_WALL + CameraPosition[0], CameraPosition[1], 0);
	al_draw_bitmap(floorbmp, START_FLOOR_X, START_FLOOR_Y, 0);
}
void map::Background() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
}

void map::Draw(float* CameraPosition) {
	Background();
	Walls(CameraPosition);
}