#include "camera.h"
void camera::Update(character&player, myClock& clock,float* CameraPosition) {
	CameraPosition[1] -= 1 * clock.camera_boost;
}
void camera::Translation(ALLEGRO_TRANSFORM &transform, float* CameraPosition) {
	al_identity_transform(&transform);
	al_translate_transform(&transform, -CameraPosition[0], -CameraPosition[1]);
	al_use_transform(&transform);
}