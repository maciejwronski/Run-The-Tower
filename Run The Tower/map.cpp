#include "map.h"

void map::Init() {
	srand(time(NULL));
	brickbmp = al_load_bitmap("game_images/brick.jpg");
	floorbmp = al_load_bitmap("game_images/floor.jpg");
	FirstBlocks();
}
void map::Walls() {
	al_draw_bitmap(brickbmp, START_WALL_X, 0, 0);
	al_draw_bitmap(brickbmp, END_WALL_X, 0, 0);
	al_draw_bitmap(floorbmp, START_FLOOR_X, START_FLOOR_Y, 0);
	//al_draw_bitmap_region(floorbmp, 0, 0, 200, 31, 400, 430,0); // 3 parametr losuje wielkosc X, 4 losuje wielkosc Y
}																// 5 parametr losuje pozycje x, 6 pozycje Y, skok na wysokosc 45
																// losowanie X miedzy 82 a 718-kl

void map::FirstBlocks() {
	int count = 0;
	for (int i = 0; i < MAX_BLOCKS; i++) {
		tab_width[i] = (rand() % MAX_RANDOM_X_SIZE) + MIN_RANDOM_X_SIZE;
		while (tab_width[i] > MAX_RANDOM_X_SIZE) {
			tab_width[i] = (rand() % MAX_RANDOM_X_SIZE) + MIN_RANDOM_X_SIZE;
		}
	}
	for (int x = 0; x < MAX_BLOCKS; x++) {
		for (int y= 0; y < 2; y++) {
			if (y == 0) {
				tab_axis[x][y] = rand() % END_WALL_X;
				while (tab_axis[x][y] < WALL_WIDTH || tab_axis[x][y] + tab_width[x] >= END_WALL_X) { 
					tab_axis[x][y] = rand() % END_WALL_X;
				}
			}
			else if(y == 1)
				tab_axis[x][y] = 430 - count * 116;
			}

		count++;
	}
}
void map::DrawFirstBlocks() {
	for (int x = 0; x < MAX_BLOCKS; x++) {
		al_draw_bitmap_region(floorbmp, 0, 0, tab_width[x], 31, tab_axis[x][0], tab_axis[x][1], 0);
	}
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
	DrawFirstBlocks();
	flipDisplay();
}