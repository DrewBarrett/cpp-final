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
	if(wave!=NULL)
    {
        al_draw_textf(font, al_color_name("white"), ScreenWidth - 100, 10, ALLEGRO_ALIGN_LEFT, "Wave: %d", *wave);
		al_draw_textf(font, al_color_name("white"), ScreenWidth - 100, 20, ALLEGRO_ALIGN_LEFT, "Enemies: %d", *wave * 5);
    }
}

void WavePanel::enable()
{
    btnNextWave.SetEnabled(true);
}

void WavePanel::disable()
{
    btnNextWave.SetEnabled(false);
}

bool WavePanel::click()
{
    if(hover)
    {
        return true;
    }
    return false;
}
