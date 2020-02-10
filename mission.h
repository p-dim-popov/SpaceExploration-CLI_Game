#ifndef MISSION_H
#define MISSION_H
#include"iMission.h"
#include<algorithm>
#include"planetRepository.h"
#include"astronautRepository.h"
#include<chrono>
#include<ctime>

class Mission : public IMission
{
public:
    Mission() {}
    virtual void explore(Planet & planet, std::vector<Astronaut*>& astronauts, bool killAll) override
    {
        for(auto &astr: astronauts)
        {
            if(!astr->canBreathe() || astr->getBag().isFull())
            {
                continue;
            }
            while (astr->canBreathe()) {
                if(planet.getItems().empty() || astr->getBag().isFull()) break;
                auto item = planet.getItems().front();
                astr->getBag().getItems().push_back(item); //добавя предмета от планетата в раницата на текущия астронавт
                int chance = rand()%100 + 1; //шансова променлива за взимането на кислород, 33% шанс да намали кислорода 2 пъти
                if (chance%3 < 0.00001)
                    astr->breathe();
                astr->breathe();
                auto planetItems = &planet.getItems();
                planetItems->erase(std::remove(planetItems->begin(), planetItems->end(), item), planetItems->end()); //премахване на предмета от планетата
            }
            if(killAll) //проверка дали е необходимо дали всички астронавти от експедицията да бъдат убити
            {
                astr->name += " - убит/изчезнал";
                astr->oxygen = 0;
            }
        }
    }
};
#endif // MISSION_H
