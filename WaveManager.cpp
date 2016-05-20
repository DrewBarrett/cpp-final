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
    numEnabled = 0;
    numEnabled++;
    timer = 0;
}

void WaveManager::update()
{
    timer++;
    for(int i = 0; i < enemies.size(); i++)
    {
        int status = enemies[i].Draw();
        if (numEnabled < enemies.size() && i == 0 && timer >= 100)
        {
            enemies[numEnabled].Enable();
            numEnabled++;
            timer = 0;
        }
        if (status == 2)
        {
            std::cout << "erasing enemy" << std::endl;
            enemies.erase(enemies.begin()+i);
        }
        if(status == 3)
        {
            enemies.erase(enemies.begin()+i);
        }
    }
}
