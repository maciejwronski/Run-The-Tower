#include "bonus.h"

Bonus::Bonus() {
	for (int i = 0; i < bonusNumber; i++) {
		given[i] = false;
		positionX[i] = 0;
		positionY[i] = 0;
		bonusType[i] = 0;
	}
}

Bonus::~Bonus() { }

void Bonus::createBonus(Block& block) {
	int count = 0;
	for (int i = 1; i < MAX_BLOCKS; i++) {
		if (i % 5 == 0) {
			positionX[count] = block.coordinateX[i] + block.width[i] / 2;
			positionY[count] = block.coordinateY[i];
			bonusType[count] = rand() % 3;
			count++;
		}
	}
}

void Bonus::drawBonus() {
	for (int i = 0; i < bonusNumber; i++) {
		if (given[i] == false){
			switch (bonusType[i]) {
			case 0:al_draw_filled_circle(positionX[i], positionY[i] - block_height, constansToDrawBonus, al_map_rgb(rand() % 255, rand() % 255, rand() % 255)); break;
			case 1: al_draw_filled_rectangle(positionX[i], positionY[i] - block_height, positionX[i] + constansToDrawBonus, positionY[i] - constansToDrawBonus - block_height, al_map_rgb(rand() % 255, rand() % 255, rand() % 255)); break;
			case 2: al_draw_filled_triangle(positionX[i], positionY[i], positionX[i] + constansToDrawBonus, positionY[i] - block_height, positionX[i] + constansToDrawBonus * 2, positionY[i], al_map_rgb(rand() % 255, rand() % 255, rand() % 255)); break;
			}
		}
	}
}

void Bonus::admitBonus(Character& character) {
	for (int i = 0; i < bonusNumber; i++) {
		if (given[i] == false) {
			if (character.getPositionX() + character.getWidth() >= positionX[i] && character.getPositionX() <= positionX[i] + constansToDrawBonus && character.getHeight() + character.getPositionY() >= positionY[i] && character.getPositionY() <= positionY[i] + constansToDrawBonus) {
				given[i] = true;
				switch (bonusType[i]) {
				case 0: character.addBonusPoints(pointsForCircle); break;
				case 1: character.addBonusPoints(pointsForRectangle); break;
				case 2: character.addBonusPoints(pointsForTriangle); break;
				}
			}
		}
	}
}

