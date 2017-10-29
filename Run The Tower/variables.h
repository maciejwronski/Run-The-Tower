#pragma once

#define FPS 45 // current fps

float DeltaTime = 1.0 / FPS;
bool in_menu = true;
bool in_game = false;
bool in_instructions = false;
bool in_options = false;
bool keys[5] = { false };

int main_menu_choosen = 25;
int brick_width = 82;

double temp;
enum KEYS { UP, DOWN, LEFT, RIGHT, SPACE };

