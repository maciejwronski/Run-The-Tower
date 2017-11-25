#include "Allegro.h"


ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_TIMER *menu_timer = NULL;
ALLEGRO_EVENT_QUEUE *menu_event_queue = NULL;
ALLEGRO_TIMER *game_timer = NULL;
ALLEGRO_EVENT_QUEUE *game_event_queue = NULL;

float DeltaTime = 1.0 / FPS;

Allegro::Allegro() {
	Conditions();
	InitAddons();
}
int Allegro::Conditions()
{

	if (!al_init()) {
	//	int error;
	//	printf("Allegro didnt load correctly. Program will exit\nPress any key to continue");
	//	scanf_s("%i", &error);
		return -1;
	}
	if (!al_install_audio()) {
	//	int error;
	//	printf("install_audio didnt  load correctly. Program will exit\nPress any key to continue");
	//	scanf_s("%i", &error);
		return -1;
	}

	if (!al_init_acodec_addon()) {
	//	int error;
	//	printf("Codec addon didnt load correctly. Program will exit\nPress any key to continue");
	//	scanf_s("%i", &error);
		return -1;
	}
	/*/	if (!al_reserve_samples(1)) {
	int error;
	printf("Reserve samples didnt load correctly. Program will exit\nPress any key to continue");
	scanf_s("%i", &error);
	return -1;
	}
	/*/
	display = al_create_display(800, 600);
	if (!display) {
	//	printf("Display didnt load correctly. Program will exit\nPress any key to continue");
		return -1;
	}

}

void Allegro::InitAddons(){
	al_install_mouse();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_set_window_title(display, "Run The Tower");
}

void Allegro::registerQueueEvents() {
	menu_event_queue = al_create_event_queue();
	menu_timer = al_create_timer(DeltaTime);
	al_register_event_source(menu_event_queue, al_get_keyboard_event_source());
	al_register_event_source(menu_event_queue, al_get_timer_event_source(menu_timer));
	al_start_timer(menu_timer);
}

Allegro::~Allegro() {
	al_destroy_timer(menu_timer);
	al_destroy_timer(game_timer);
	if(game_event_queue != NULL)
		al_destroy_event_queue(game_event_queue);
	al_destroy_display(display);
}

void Allegro::changeEvents() {
	al_stop_timer(menu_timer);
	al_destroy_event_queue(menu_event_queue);
	game_event_queue = al_create_event_queue();
	game_timer = al_create_timer(DeltaTime);
	al_register_event_source(game_event_queue, al_get_keyboard_event_source());
	al_register_event_source(game_event_queue, al_get_timer_event_source(game_timer));
	al_start_timer(game_timer);
}