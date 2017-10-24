#pragma once


#define FPS 45 // current fps

#define START_WALL_X 0 // where left wall starts
#define END_WALL_X 718 // where right wall starts
#define WALL_WIDTH 82 // width of wall

#define START_FLOOR_X 82 // where start-floor starts x axis
#define START_FLOOR_Y 530 // where start-floor starts y axis

#define START_PLAYER_X 400 // start of player, x axis
#define START_PLAYER_Y 460 // start of player, y axis

#define MIDDLE_X_CLOCK 50
#define MIDDLE_Y_CLOCK 75
#define RADIUS_OF_CLOCK 50

#define M_PI 3.14159265358979323846


const int RGB_clock[3] = { 0,0,0 }; // clock line constants
double x_c, y_c;
double current_degree = 0;
int degree = 0;
float DeltaTime = 1.0 / FPS;
float run_boost = 0.8; // used for run-boost
bool in_menu = true;
bool in_game = false;
bool in_instructions = false;
bool in_options = false;
bool keys[5] = { false };

int main_menu_choosen = 25;
int brick_width;

clock_t start; //
double duration; // used to check, how long player is pressing a single button, to boost his run

clock_t my_clock;
int my_time;
int old_time = 34;
bool first_tick = true;
enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE };

character player;
