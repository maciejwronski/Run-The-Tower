#pragma once
#include <iostream>
#include "character.h"
#include "allegro.h"
#include "clock.h"

static const int startCameraFromPlayerPoints = 30;

class Camera {
	friend class Map;
	friend class Character;

	float CameraPosition[2];
public:
	Camera();
	~Camera();
	void update(Character&player, MyClock& clock, float* CameraPosition);
	void translation(ALLEGRO_TRANSFORM &transform, float* CameraPosition);
	bool cameraShouldStart(Map& map, Character& character);
	bool playerHasFallenDown(Map& map, Character& character);
	float* getCameraPos();
};