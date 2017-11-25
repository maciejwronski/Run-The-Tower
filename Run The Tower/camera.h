#pragma once
#include "character.h"
#include "allegro.h"
#include "clock.h"
#include "map.h"
static int startCameraFromPlayerPoints = 30;

class Camera {
	float CameraPosition[2];
	ALLEGRO_TRANSFORM cameratrans;
public:
	Camera();
	~Camera();
	void Update(Character&player, MyClock& clock, float* CameraPosition);
	void Translation(ALLEGRO_TRANSFORM &transform, float* CameraPosition);
	bool CameraShouldStart(Map& map, Character& character);
	float* GetCameraPos();
};
