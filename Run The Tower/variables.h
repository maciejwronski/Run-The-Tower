#pragma once

#include "includes.h"

#define FPS 60

float DeltaTime = 1.0 / FPS;

bool in_menu = true;
bool in_game = false;
bool in_instructions = false;
bool in_options = false;

bool keys[4] = { false };

int main_menu_choosen = 25;
enum KEYS { UP, DOWN, LEFT, RIGHT };
