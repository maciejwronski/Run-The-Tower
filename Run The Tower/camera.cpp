#include "camera.h"

Camera::Camera() {
	CameraPosition[0] = 0;
	CameraPosition[1] = 0;
}

Camera::~Camera() { }

void Camera::update(Character&player, MyClock& clock, float* CameraPosition) {
	CameraPosition[1] -= 1 * clock.cameraBoost;
}

void Camera::translation(ALLEGRO_TRANSFORM &transform, float* CameraPosition) {
	al_identity_transform(&transform);
	al_translate_transform(&transform, -CameraPosition[0], -CameraPosition[1]);
	al_use_transform(&transform);
}

bool Camera::playerHasFallenDown(Map& map, Character& character) {
	if (map.mapFalling) {
		if (character.getPositionY() > 0) {
			if ((abs(CameraPosition[1]) - abs(character.getPositionY() - 128) >= 450))
				return true;
		}
		else if ((abs(CameraPosition[1]) - abs(character.getPositionY()) >= 600))
			return true;
		else
			return false;
	}
	return false;
}

bool Camera::cameraShouldStart(Map& map, Character& character) {
	if (character.getScore() >= startCameraFromPlayerPoints) {
		map.mapFalling = true;
		return true;
	}
	else return false;
}

float* Camera::getCameraPos() {
	return CameraPosition;
}