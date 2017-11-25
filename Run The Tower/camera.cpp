#include "camera.h"

Camera::Camera() {
	CameraPosition[0] = 0;
	CameraPosition[1] = 0;
}
Camera::~Camera() {
}
void Camera::Update(Character&player, MyClock& clock,float* CameraPosition) {
	CameraPosition[1] -= 1 * clock.camera_boost;
}
void Camera::Translation(ALLEGRO_TRANSFORM &transform, float* CameraPosition) {
	al_identity_transform(&transform);
	al_translate_transform(&transform, -CameraPosition[0], -CameraPosition[1]);
	al_use_transform(&transform);
}
bool Camera::CameraShouldStart(Map& map, Character& character){
	if (character.getScore() >= startCameraFromPlayerPoints) {
		map.mapFalling = true;
		return true;
	}
	else return false;
}
float* Camera::GetCameraPos() {
	return CameraPosition;
}