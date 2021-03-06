#include <iostream>
#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include "Button.h"
#include "TowerMenu.h"
#include "MapGrid.h"
#include "GUI.h"
//Dynamic Link
//Drew Barrett
#define ScreenWidth 1024
#define ScreenHeight 768
int init();
ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_AUDIO_STREAM *soundtrack = NULL;
ALLEGRO_VOICE*  voice;
ALLEGRO_MIXER*  mixer;
ALLEGRO_FONT *font = NULL;
ALLEGRO_EVENT_QUEUE *queue;
ALLEGRO_TIMER *timer;
ALLEGRO_MOUSE_STATE state;

int main(int argc, char **argv)
{
	init();
	
	queue = al_create_event_queue();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	timer = al_create_timer(1.0 / 60);
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_start_timer(timer);

	GUI gui = GUI(font);


	bool redraw = true;
	bool title = true;
	while (1) {
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			break;
		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				break;
			if (title) {
				title = false;
			}
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (title) {
				title = false;
			}
		}
		if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			al_get_mouse_state(&state);
			gui.MouseClicked();
		}
		if (event.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		if (redraw && al_is_event_queue_empty(queue)) {
			redraw = false;
			al_set_target_bitmap(al_get_backbuffer(display));
			al_clear_to_color(al_map_rgb(0, 0, 0));
			if (title) {
				al_clear_to_color(al_map_rgb(0, 0, 0));
				al_draw_text(font, al_color_name("white"), ScreenWidth / 2, 0, ALLEGRO_ALIGN_CENTRE, "Kiwi Tower Defense");
				al_draw_text(font, al_color_name("white"), ScreenWidth / 2, 20, ALLEGRO_ALIGN_CENTRE, "Click on a grid square for information about the tile on it");
				al_draw_text(font, al_color_name("white"), ScreenWidth / 2, 40, ALLEGRO_ALIGN_CENTRE, "Hover over a tower on the left to see its information");
				al_draw_text(font, al_color_name("white"), ScreenWidth / 2, 60, ALLEGRO_ALIGN_CENTRE, "Click a tower after clicking a grid square to spend your money and buy it");
				al_draw_text(font, al_color_name("white"), ScreenWidth / 2, 80, ALLEGRO_ALIGN_CENTRE, "You can adjust the path the enemies take by building your towers in their way");
				al_draw_text(font, al_color_name("white"), ScreenWidth / 2, 100, ALLEGRO_ALIGN_CENTRE, "Balance your money between towers and walls to get the perfect balance!");
				al_draw_text(font, al_color_name("white"), ScreenWidth / 2, 120, ALLEGRO_ALIGN_CENTRE, "When you have spent all of the money you want to, click next wave in the bottom right.");
				//al_draw_bitmap(rules, (ScreenWidth / 2) - (al_get_bitmap_width(rules)/2) , 100, 0);
				al_draw_text(font, al_color_name("white"), ScreenWidth / 2, ScreenHeight - 150, ALLEGRO_ALIGN_CENTRE,
					"Press any key to continue or ESC to exit...");
				al_draw_text(font, al_color_name("white"), ScreenWidth / 2, ScreenHeight - 100, ALLEGRO_ALIGN_CENTRE,
					"Created by Drew Barrett and Dakota Robey");
			}
			else {
				al_get_mouse_state(&state);
				gui.Draw(state);
				//mapgrid.draw(state);
			}
			al_flip_display();
		}
	}
	al_destroy_display(display);
	return 0;
}

void updateLoad(const char *text) {
	al_clear_to_color(al_map_rgb(0, 0, 0));
	al_draw_text(font, al_color_name("white"), ScreenWidth / 2, 0, ALLEGRO_ALIGN_CENTRE, text);
	al_flip_display();
}

int init() {
	
	if (!al_init())
	{
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	display = al_create_display(ScreenWidth, ScreenHeight);
	if (!display)
	{
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}
	
	al_init_font_addon();
	al_init_ttf_addon();
	font = al_load_font("comic.ttf", 20, 0);
	if (!font) {
		fprintf(stderr, "Could not load 'comic.ttf'.\n");
		return -1;
	}
	updateLoad("loading image addon...");
	al_init_image_addon();
	updateLoad("loading primitives addon...");
	if (!al_init_primitives_addon()) {
		fprintf(stderr, "failed to initialize primitives!\n");
		return -1;
	}
	updateLoad("installing mouse...");
	al_install_mouse();
	updateLoad("installing keyboard...");
	al_install_keyboard();
	updateLoad("installing audio...");
	if (!al_install_audio()) {
		fprintf(stderr, "failed to initialize audio!\n");
		return -1;
	}
	updateLoad("initializing audio codecs...");
	if (!al_init_acodec_addon()) {
		fprintf(stderr, "failed to initialize audio codecs!\n");
		return -1;
	}
	updateLoad("reserving audio samples...");
	//change this for amount of simultanious noises playing
	if (!al_reserve_samples(2)) {
		fprintf(stderr, "failed to reserve samples!\n");
		return -1;
	}
	updateLoad("loading voice...");
	voice = al_create_voice(44100, ALLEGRO_AUDIO_DEPTH_INT16, ALLEGRO_CHANNEL_CONF_2);
	if (!voice) {
		fprintf(stderr, "Could not create ALLEGRO_VOICE.\n");
		return -1;
	}
	
	updateLoad("loading mixer...");
	mixer = al_create_mixer(44100, ALLEGRO_AUDIO_DEPTH_FLOAT32, ALLEGRO_CHANNEL_CONF_2);
	if (!mixer)
	{
		fprintf(stderr, "Could not create ALLEGRO_MIXER.\n");
		return -1;
	}
		
	if (!al_attach_mixer_to_voice(mixer, voice)) {
		fprintf(stderr, "al_attach_mixer_to_voice failed.\n");
		return -1;
		
	}
	updateLoad("loading soundtrack...");
	soundtrack = al_load_audio_stream("soundtrack.ogg", 4, 2048);

	if (!soundtrack) {
		fprintf(stderr, "Could not load sample from soundtrack.mp3!\n");
		return -1;
	}
	if (!al_set_audio_stream_gain(soundtrack, .5))
	{
		fprintf(stderr, "changing volume failed!");
		return -1;
	}
	//al_play_sample(soundtrack, 0.5, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	if (!al_attach_audio_stream_to_mixer(soundtrack, mixer)) {
		fprintf(stderr, "al_attach_audio_stream_to_mixer failed.\n");
		return -1;
	}
	
	updateLoad("loading gui! do not click!");
}
