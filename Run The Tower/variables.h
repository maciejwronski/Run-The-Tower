#pragma once

#include "includes.h"

#define FPS 45
#define START_WALL_X 0
#define END_WALL_X 718
#define WALL_WIDTH 82
#define START_FLOOR_X 82
#define START_FLOOR_Y 530
#define START_PLAYER_X 400
#define START_PLAYER_Y 460


float DeltaTime = 1.0 / FPS;

bool in_menu = true;
bool in_game = false;
bool in_instructions = false;
bool in_options = false;
bool keys[4] = { false };

int main_menu_choosen = 25;
int brick_width;
enum KEYS { UP, DOWN, LEFT, RIGHT };

