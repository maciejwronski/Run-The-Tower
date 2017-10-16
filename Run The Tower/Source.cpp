#include "variables.h"
#include "allegro_stuff.h"
#include "character.h"
#include "some_functions.h"

character player(START_PLAYER_X, START_PLAYER_Y);

int pre_start_game() {

	if (!al_init()) {
		int error;
		printf("Allegro didnt load correctly. Program will exit\nPress any key to continue");
		scanf_s("%i", &error);
		return -1;
	}
	if (!al_install_audio()) {
	int error;
	printf("install_audio didnt  load correctly. Program will exit\nPress any key to continue");
	scanf_s("%i", &error);
	return -1;
	}

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
	display = al_create_display(800, 600);
	if (!display) {
		printf("Display didnt load correctly. Program will exit\nPress any key to continue");
		return -1;
	}

}

void init_addons() {
	al_install_mouse();
	al_init_font_addon();
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
void initialize_bitmaps() {
	startbmp = al_load_bitmap("menu_images/start.png");
	instructionsbmp = al_load_bitmap("menu_images/instructions.png");
	optionsbmp = al_load_bitmap("menu_images/options.png");
	exitbmp = al_load_bitmap("menu_images/exit.png");
	menusquarebmp = al_load_bitmap("menu_images/choosen.png");
	logobmp = al_load_bitmap("menu_images/logo.png");
	brickbmp = al_load_bitmap("game_images/brick.jpg");
	floorbmp = al_load_bitmap("game_images/floor.jpg");
	player_left = al_load_bitmap("player_images/left.png");
	player_right = al_load_bitmap("player_images/right.png");
	font = al_load_font("fonts/times.ttf", 24, 0);

	brick_width = al_get_bitmap_width(brickbmp);
	player.set_width(al_get_bitmap_width(player_left));
	player.set_height(al_get_bitmap_height(player_left));
}
void destroy_everything() {
	al_destroy_display(display);
	al_destroy_timer(menu_timer);
}

void menu_loop() {
	if (in_menu && !in_game && !in_instructions && !in_options) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_bitmap(logobmp, 0, 20, 0);
		al_draw_bitmap(startbmp, 50, 300, 0);
		al_draw_bitmap(instructionsbmp, 50, 350, 0);
		al_draw_bitmap(optionsbmp, 50, 400, 0);
		al_draw_bitmap(exitbmp, 50, 450, 0);
		al_draw_bitmap(menusquarebmp, 20, 300 + main_menu_choosen, 0);
	}
	else if (in_menu && !in_game && in_instructions && !in_options) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_text(font, al_map_rgb(255, 255, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "Tutaj jakies instrukcje mordeczko!");
	}
	else if (in_menu && !in_game && !in_instructions && in_options) {
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_text(font, al_map_rgb(255, 255, 255), 640 / 2, (480 / 4), ALLEGRO_ALIGN_CENTRE, "Tutaj jakies opcje mordeczko!");
	}
	ALLEGRO_EVENT ev;
	al_wait_for_event(menu_event_queue, &ev);
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP: keys[UP] = true; if (!in_options && !in_game && !in_instructions) if (main_menu_choosen - 50 > 0) main_menu_choosen -= 50;  break; // adding values to position of bmp in range of 25/175
		case ALLEGRO_KEY_DOWN: keys[DOWN] = true; if (!in_options && !in_game && !in_instructions) if (main_menu_choosen + 50 <= 175) main_menu_choosen += 50; break;
		case ALLEGRO_KEY_RIGHT: keys[RIGHT] = true;  break;
		case ALLEGRO_KEY_LEFT: keys[LEFT] = true;  break;
		case ALLEGRO_KEY_ENTER:  break;
		case ALLEGRO_KEY_ESCAPE: if (in_instructions) in_instructions = false; if (in_options) in_options = false; al_flip_display();  break;
		}
	}
	else if (ev.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch (ev.keyboard.keycode) {
		case ALLEGRO_KEY_UP: keys[UP] = false;  break;
		case ALLEGRO_KEY_DOWN: keys[DOWN] = false;  break;
		case ALLEGRO_KEY_RIGHT: keys[RIGHT] = false;  break;
		case ALLEGRO_KEY_LEFT: keys[LEFT] = false;  break;
		case ALLEGRO_KEY_ENTER:
			if (!in_options && !in_game && !in_instructions) {
				switch (main_menu_choosen) {
				case 25: 
					al_stop_timer(menu_timer);
					al_destroy_event_queue(menu_event_queue);
					game_event_queue = al_create_event_queue();
					game_timer = al_create_timer(DeltaTime);
					al_register_event_source(game_event_queue, al_get_keyboard_event_source());
					al_register_event_source(game_event_queue, al_get_timer_event_source(game_timer));
					al_start_timer(game_timer);
					in_game = true;
					in_menu = false; 
					al_clear_to_color(al_map_rgb(0, 0, 0));
					break;
				case 75: in_instructions = true; break;
				case 125: in_options = true; break;
				case 175: in_menu = false; break;
				}
			}
			break;
		case ALLEGRO_KEY_ESCAPE: break;
		}
	}
	al_flip_display();
}
void game_loop() {
	int temp1, temp2; // used for set x,y
	ALLEGRO_EVENT ev1;
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_bitmap(brickbmp, START_WALL_X, 0, 0);
	al_draw_bitmap(brickbmp, END_WALL_X, 0, 0);
	al_draw_bitmap(floorbmp, START_FLOOR_X, START_FLOOR_Y, 0);
	al_draw_bitmap(player_left, player.get_x(), player.get_y(), 0);
	al_wait_for_event(game_event_queue, &ev1);
	if (ev1.type == ALLEGRO_EVENT_KEY_DOWN) {
		switch (ev1.keyboard.keycode) {
		case ALLEGRO_KEY_RIGHT: keys[RIGHT] = true;   break;
		case ALLEGRO_KEY_LEFT: keys[LEFT] = true;  break;
		case ALLEGRO_KEY_SPACE: keys[RIGHT] = true;   break;

		}
	}
	else if (ev1.type == ALLEGRO_EVENT_KEY_UP)
	{
		switch (ev1.keyboard.keycode) {
		case ALLEGRO_KEY_RIGHT: keys[RIGHT] = false;  break;
		case ALLEGRO_KEY_LEFT: keys[LEFT] = false;  break;
		}
	}
	else if (ev1.type == ALLEGRO_EVENT_TIMER)
	{
		if (keys[RIGHT]) {
			if (!collision(player.get_x(), player.get_width(), END_WALL_X, brick_width)) {
				temp2 = player.get_x() + keys[RIGHT] * 10;
				player.set_x(temp2);
			}
		}
		else if (keys[LEFT]) {
			if (!collision(player.get_x(), player.get_width(), START_WALL_X, brick_width)) {
				temp2 = player.get_x() - 10;
				player.set_x(temp2);
			}
		}
		al_draw_bitmap(player_left, player.get_x(), player.get_y(), 0);
	}
	al_flip_display();
}
int main(void) {
	pre_start_game();
	init_addons();
	register_events_queue_timer();
	initialize_bitmaps();
	while (in_menu) {
		menu_loop();
	}
	while (in_game) {
		game_loop();
	}
	destroy_everything();
	return 0;
}