#ifndef WAVEPANEL_H
#define WAVEPANEL_H
#define ScreenWidth 1024
#define ScreenHeight 768
#include "Button.h"
class WavePanel
{
public:
	WavePanel();
	void Draw(ALLEGRO_MOUSE_STATE);
private:
	Button btnNextWave;
};
#endif