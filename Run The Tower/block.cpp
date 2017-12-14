#include "block.h"

Block::Block() {
	srand(time(NULL));
	for (int i = 0; i < MAX_BLOCKS; i++) {
		coordinateX[i] = 0;
		coordinateY[i] = 0;
		width[i] = 0;
	}
	floorbmp = al_load_bitmap("game_images/floor.jpg");
	createBlocks();
}

Block::~Block() {
	al_destroy_bitmap(floorbmp);
}

float* Block::getCoordinateX() {
	return coordinateX;
}

float* Block::getCoordinateY() {
	return coordinateY;
}

float* Block::getWidth() {
	return width;
}

bool Block::checkIfPlayerIsFlying(Character& player) {
	for (int i = 1; i < MAX_BLOCKS; i++) {
		if ((player.getPositionX() + player.getWidth() < coordinateX[i] || player.getPositionX() > coordinateX[i] + width[i]) && player.getPositionY() + player.getHeight() >= coordinateY[i] && player.getHeight() <= coordinateY[i] + block_height) {
			return true;
		}
	}
}


void Block::collidingWithPlayer(Character& player) {
	for (int i = 1; i < MAX_BLOCKS; i++) {
		if (player.getPositionX() + player.getWidth() > coordinateX[i] && player.getPositionX() < coordinateX[i] + width[i] && player.getPositionY() + player.getHeight() >= coordinateY[i] && player.getPositionY() <= coordinateY[i] + block_height && (player.getPositionY() + player.getHeight() < block_height + coordinateY[i])) {
			player.onGround = true;
			player.jumped = false;
			player.setPositionY(coordinateY[i] - player.bitmapHeight);
			player.updateScore(i);
			player.setVelocityX(0);
			player.setVelocityY(0);
		}
	}
}

void Block::createBlocks() {
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

void Block::drawBlocks() {
	for (int i = 1; i < MAX_BLOCKS; i++) {
		al_draw_bitmap_region(floorbmp, 0, 0, width[i], block_height, coordinateX[i], coordinateY[i], 0);
	}
}