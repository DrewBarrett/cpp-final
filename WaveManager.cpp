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
        for(int i = 0; i < 5; i++)
        {
            enemies.push_back(Enemy(1, pathx, pathy));
        }
    }
    enemies[0].Enable();
    numEnabled++;
}

void WaveManager::update()
{
    for(int i = 0; i < enemies.size(); i++)
    {
        int status = enemies[i].Draw();
        if (numEnabled < enemies.size() && i == 0 && status == 1)
        {
            enemies[numEnabled].Enable();
            numEnabled++;
        }
        if (i == 0 && status == 2)
        {
            enemies.erase(enemies.begin());
        }
    }
}
