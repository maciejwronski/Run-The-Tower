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
ALLEGRO_TIMER *menu_timer = NULL;
ALLEGRO_EVENT_QUEUE *menu_event_queue = NULL;
ALLEGRO_BITMAP *startbmp = NULL;
ALLEGRO_BITMAP *instructionsbmp = NULL;
ALLEGRO_BITMAP *optionsbmp = NULL;
ALLEGRO_BITMAP *exitbmp = NULL;
ALLEGRO_BITMAP *menusquarebmp = NULL;
ALLEGRO_BITMAP *logobmp = NULL;

float DeltaTime = 1.0 / FPS;
bool left_menu;
bool keys[4] = { false };
int main_menu_choosen = 25;

enum KEYS { UP, DOWN, LEFT, RIGHT };

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
	menu_event_queue = al_create_event_queue();
	menu_timer = al_create_timer(DeltaTime);
	al_register_event_source(menu_event_queue, al_get_keyboard_event_source());
	al_register_event_source(menu_event_queue, al_get_timer_event_source(menu_timer));
	al_start_timer(menu_timer);
}
void destroy_everything() {
	al_destroy_display(display);
	al_destroy_timer(menu_timer);
	al_destroy_event_queue(menu_event_queue);
}
void initialize_bitmaps() {
	startbmp = al_load_bitmap("menu_images/start.png");
	instructionsbmp = al_load_bitmap("menu_images/instructions.png");
	optionsbmp = al_load_bitmap("menu_images/options.png");
	exitbmp = al_load_bitmap("menu_images/exit.png");
	menusquarebmp = al_load_bitmap("menu_images/choosen.png");
	logobmp = al_load_bitmap("menu_images/logo.png");
}
int main(void) {
	pre_start_game();
	init_addons();
	register_events_queue_timer();
	initialize_bitmaps();
	while (!left_menu) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(logobmp, 0, 20, 0);
		al_draw_bitmap(startbmp, 50, 300, 0);
		al_draw_bitmap(instructionsbmp, 50, 350, 0);
		al_draw_bitmap(optionsbmp, 50, 400, 0);
		al_draw_bitmap(exitbmp, 50, 450, 0);
		al_draw_bitmap(menusquarebmp, 20, 300+main_menu_choosen, 0);
		ALLEGRO_EVENT ev;
		al_wait_for_event(menu_event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP: keys[UP] = true; if(main_menu_choosen - 50 > 0) main_menu_choosen -= 50;  break; // adding values to position of bmp in range of 25/175
			case ALLEGRO_KEY_DOWN: keys[DOWN] = true; if (main_menu_choosen + 50 <= 175 ) main_menu_choosen += 50; break;
			case ALLEGRO_KEY_RIGHT: keys[RIGHT] = true;  break;
			case ALLEGRO_KEY_LEFT: keys[LEFT] = true;  break;
			case ALLEGRO_KEY_ENTER:  break;
			case ALLEGRO_KEY_ESCAPE: break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP: keys[UP] = false;  break;
			case ALLEGRO_KEY_DOWN: keys[DOWN] = false;  break;
			case ALLEGRO_KEY_RIGHT: keys[RIGHT] = false;  break;
			case ALLEGRO_KEY_LEFT: keys[LEFT] = false;  break;
			case ALLEGRO_KEY_ENTER:break;
			case ALLEGRO_KEY_ESCAPE: break;
			}
		}
		al_flip_display();
	}
	destroy_everything();
	return 0;
}