#pragma once
#include "character.h"
#include "allegro.h"
#include "clock.h"

static int startCameraFromPlayerPoints = 30;

class Camera {
	float CameraPosition[2] = { 0,0 };
	ALLEGRO_TRANSFORM cameratrans;
public:

	void Update(Character&player, MyClock& clock, float* CameraPosition);
	void Translation(ALLEGRO_TRANSFORM &transform, float* CameraPosition);
	bool CameraShouldStart(Character& character);
	float* GetCameraPos();
};
