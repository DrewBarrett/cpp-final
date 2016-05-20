#ifndef WAVEPANEL_H
#define WAVEPANEL_H
#define ScreenWidth 1024
#define ScreenHeight 768
#include "Button.h"
class WavePanel
{
public:
	WavePanel();
	void Draw(ALLEGRO_MOUSE_STATE, int, int);
	bool click();
	void enable();
	void disable();
	void setWavePointer(int *val) { wave = val; }
private:
	Button btnNextWave;
	bool hover = false;
	int *wave = NULL;
	ALLEGRO_FONT *font = al_load_font("comic.ttf", 20, 0);
};
#endif
