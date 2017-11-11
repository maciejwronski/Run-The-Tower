#include "block.h"
void Block::Init() {
	srand(time(NULL));
	floorbmp = al_load_bitmap("game_images/floor.jpg");
	CreateBlocks();
}

void Block::CollidingWithPlayer(Character& player) { 
	for (int i = 1; i < MAX_BLOCKS; i++) {
		if (player.x + player.width > coordinateX[i] && player.x < coordinateX[i] + width[i] && player.y + player.height >= coordinateY[i] && player.y <= coordinateY[i] + block_height && (player.y + player.height < block_height + coordinateY[i])) {
			player.onGround = true;
			player.y = coordinateY[i] - player.height;
			player.updateScore(player,i);
		}
	}
}
bool Block::CheckIfPlayerIsFlying(Character& player) {
	for (int i = 1; i < MAX_BLOCKS; i++) {
		if ((player.x + player.width < coordinateX[i] || player.x > coordinateX[i] + width[i]) && player.y + player.height >= coordinateY[i] && player.y <= coordinateY[i] + block_height) {
			return true;
		}
	}
}
void Block::CreateBlocks() {
	int count = 0;
	coordinateX[0] = START_FLOOR_X;
	coordinateY[0] = START_FLOOR_Y;
	width[0] = al_get_bitmap_width(floorbmp);
	for (int i = 1; i < MAX_BLOCKS; i++) {
		width[i] = (rand() % MAX_RANDOM_X_SIZE) + MIN_RANDOM_X_SIZE;
		while (width[i] > MAX_RANDOM_X_SIZE) {
			width[i] = (rand() % MAX_RANDOM_X_SIZE) + MIN_RANDOM_X_SIZE;
		}
	}
	for (int i = 1; i < MAX_BLOCKS; i++) {
				coordinateX[i] = rand() % START_OF_RIGHT_WALL;
				while (coordinateX[i] < WALL_WIDTH || coordinateX[i] + width[i] >= START_OF_RIGHT_WALL) {
					coordinateX[i] = rand() % START_OF_RIGHT_WALL;
				}
			coordinateY[i] = 430 - count * 116;
			count++;
		}
}
void Block::DrawBlocks() {
	for (int i = 1; i < MAX_BLOCKS; i++) {
		al_draw_bitmap_region(floorbmp, 0, 0, width[i], block_height, coordinateX[i], coordinateY[i], 0);
	}
}
void Block::Destroy() {
	al_destroy_bitmap(floorbmp);
}