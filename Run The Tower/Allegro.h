#pragma once
#include "allegro5\allegro.h"
#include<allegro5\allegro.h>
#include<allegro5\allegro_native_dialog.h>
#include<allegro5\allegro_font.h>
#include<allegro5\allegro_ttf.h>
#include<allegro5\allegro_image.h>
#include<allegro5\allegro_primitives.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\monitor.h>

#define FPS 45 // current fps
extern float DeltaTime;
extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_TIMER *menu_timer;
extern ALLEGRO_EVENT_QUEUE *menu_event_queue;
extern ALLEGRO_TIMER *game_timer;
extern ALLEGRO_EVENT_QUEUE *game_event_queue;

class Allegro {
public:
	Allegro();
	~Allegro();
	int Conditions();
	void InitAddons();
	void registerQueueEvents();
	void changeEvents();
};