#include "WaveManager.h"



WaveManager::WaveManager()
{

}

void WaveManager::AdvanceWave(std::vector<int> pathx, std::vector<int> pathy)
{
    wave++;
    enemies.clear();
    if(wave>=1)
    {
        for(int i = 0; i < 5*wave; i++)
        {
            enemies.push_back(Enemy(1, pathx, pathy));
        }
    }
    //enemies[0].Enable();
    numEnabled = 0;
    numGone = 0;
    //numEnabled++;
    timer = 0;
    waveInProgress = true;
}

void WaveManager::update(int *money, int *health)
{
    timer++;
    for(int i = 0; i < enemies.size(); i++)
    {
        int status = enemies[i].Draw();
        //std::cout << "drawing enemy at " << enemies[i].GetX() << " " << enemies[i].GetY() << " " << enemies[i].isEnabled() << std::endl;
        if (numEnabled < wave*5 && i == 0 && timer >= 100)
        {
            enemies[numEnabled-numGone].Enable();
            numEnabled++;
            std::cout << "num enabled is now: " << numEnabled << std::endl;
            timer = 0;
        }
        if (status == 2)
        {
            std::cout << "erasing enemy" << std::endl;
            enemies.erase(enemies.begin()+i);
            numGone++;
			*health -= 1;
        }
        if(status == 3)
        {
            std::cout << "dead enemy erasing" << std::endl;
            enemies.erase(enemies.begin()+i);
            numGone++;
			*money += 25;
        }
    }
    if(enemies.size() == 0)
    {
        waveInProgress = false;
		//*money += 100;
    }
}
