#include "block.h"

void block::Init() {
	srand(time(NULL));
	floorbmp = al_load_bitmap("game_images/floor.jpg");
	CreateBlocks();
}
void block::CollidingWithPlayer(character& player) { // kolizja gracza z bloczkami
	for (int i = 0; i < MAX_BLOCKS; i++) {
		if (player.x + player.width >= coordinate[i][0] && player.x <= coordinate[i][0] + width[i] && player.y + player.height >= coordinate[i][1] && player.y <= coordinate[i][1] + block_height) {
			player.onGround = true;
		}
		else {
			player.onGround = false;
		}
	}

}
void block::CreateBlocks() { // tworzenie bloczków na mapie, 0 to pod³oga
	int count = 0;
	coordinate[0][0] = START_FLOOR_X;
	coordinate[0][1] = START_FLOOR_Y;
	width[0] = al_get_bitmap_width(floorbmp);
	for (int i = 1; i < MAX_BLOCKS; i++) {
		width[i] = (rand() % MAX_RANDOM_X_SIZE) + MIN_RANDOM_X_SIZE;
		while (width[i] > MAX_RANDOM_X_SIZE) {
			width[i] = (rand() % MAX_RANDOM_X_SIZE) + MIN_RANDOM_X_SIZE;
		}
	}
	for (int x = 1; x < MAX_BLOCKS; x++) {
		for (int y = 0; y < 2; y++) {
			if (y == 0) {
				coordinate[x][y] = rand() % START_OF_RIGHT_WALL;
				while (coordinate[x][y] < WALL_WIDTH || coordinate[x][y] + width[x] >= START_OF_RIGHT_WALL) {
					coordinate[x][y] = rand() % START_OF_RIGHT_WALL;
				}
			}
			else if (y == 1)
				coordinate[x][y] = 430 - count * 116;
		}

		count++;
	}
}
void block::DrawBlocks() {
	for (int x = 1; x < MAX_BLOCKS; x++) {
		al_draw_bitmap_region(floorbmp, 0, 0, width[x], block_height, coordinate[x][0], coordinate[x][1], 0);
	}
	al_flip_display();
}