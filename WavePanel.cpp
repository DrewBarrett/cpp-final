#include "WavePanel.h"



WavePanel::WavePanel()
{
	btnNextWave = Button(ScreenWidth - 150, ScreenHeight - 235, 140, "Next Wave");
}

void WavePanel::Draw(ALLEGRO_MOUSE_STATE state)
{
	btnNextWave.draw(state);
}