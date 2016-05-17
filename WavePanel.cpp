#include "WavePanel.h"



WavePanel::WavePanel()
{
	btnNextWave = Button(ScreenWidth - 150, ScreenHeight - 235, 140, "Next Wave");
}

void WavePanel::Draw(ALLEGRO_MOUSE_STATE state)
{
	hover = false;
	if(btnNextWave.draw(state) == 2){
        hover = true;
	}
}

bool WavePanel::click()
{
    if(hover)
    {
        return true;
    }
    return false;
}
