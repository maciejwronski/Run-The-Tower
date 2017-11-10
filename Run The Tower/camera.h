#pragma once
#include "character.h"
#include "allegro.h"
#include "clock.h"
extern float CameraPosition[2];
class camera {
public:
	
	void Update(character&player, myClock& clock, float* CameraPosition);
	void Translation(ALLEGRO_TRANSFORM &transform, float* CameraPosition);
};
