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

}
