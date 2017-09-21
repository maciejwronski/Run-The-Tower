#include<iostream>
#include<allegro5\allegro.h>
#include<allegro5\allegro_native_dialog.h>
#include<allegro5\allegro_font.h>
#include<allegro5\allegro_ttf.h>
#include<allegro5\allegro_image.h>
#include<allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\monitor.h>
#include <ctime>
#include <math.h>

#define FPS 60

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;

float DeltaTime = 1.0 / FPS;
bool left_game;

int pre_start_game() {
	
	if (!al_init()) {
		int error;
		printf("Allegro didnt load correctly. Program will exit\nPress any key to continue");
		scanf_s("%i", &error);
		return -1;
	}
/*/	if (!al_install_audio()) {
		int error;
		printf("install_audio didnt  load correctly. Program will exit\nPress any key to continue");
		scanf_s("%i", &error);
		return -1;
	}/*/
	if (!al_init_acodec_addon()) {
		int error;
		printf("Codec addon didnt load correctly. Program will exit\nPress any key to continue");
		scanf_s("%i", &error);
		return -1;
	}
	/*/	if (!al_reserve_samples(1)) {
		int error;
		printf("Reserve samples didnt load correctly. Program will exit\nPress any key to continue");
		scanf_s("%i", &error);
		return -1;
	}
	/*/
	display = al_create_display(640, 600);
	if (!display) {
		printf("Display didnt load correctly. Program will exit\nPress any key to continue");
		return -1;
	}
}

void init_addons() {
	al_init_font_addon();
	al_install_mouse();
	al_init_ttf_addon();
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_set_window_title(display, "Run The Tower");
}

void register_events_queue_timer() {
	event_queue = al_create_event_queue();
	timer = al_create_timer(DeltaTime);
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_start_timer(timer);
}
void destroy_everything() {
	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);
}
int main(void) {
	pre_start_game();
	init_addons();
	register_events_queue_timer();
	while (!left_game) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
	}
	destroy_everything();
	return 0;
}