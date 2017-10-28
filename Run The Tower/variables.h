#pragma once

#define FPS 45 // current fps

#define START_WALL_X 0 // where left wall starts
#define END_WALL_X 718 // where right wall starts
#define WALL_WIDTH 82 // width of wall

#define START_FLOOR_X 82 // where start-floor starts x axis
#define START_FLOOR_Y 530 // where start-floor starts y axis

#define START_PLAYER_X 400 // start of player, x axis
#define START_PLAYER_Y 460 // start of player, y axis

float DeltaTime = 1.0 / FPS;
bool in_menu = true;
bool in_game = false;
bool in_instructions = false;
bool in_options = false;
bool keys[5] = { false };

int main_menu_choosen = 25;
int brick_width;

double temp;
enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE };


character player;
myClock newclock;