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
    Mission() = default;
    virtual void explore(Planet & planet, std::vector<Astronaut*>& astronauts, bool killAll) override
    {
        for(auto &astronaut: astronauts)
        {
            if(!astronaut->canBreathe() || astronaut->getBag().isFull())
            {
                continue;
            }
            while (astronaut->canBreathe()) {
                if(planet.getItems().empty() || astronaut->getBag().isFull()) break;
                auto item = planet.getItems().front();
                astronaut->getBag().getItems().push_back(item); //добавя предмета от планетата в раницата на текущия астронавт
                int chance = rand()%100 + 1; //шансова променлива за взимането на кислород, 33% шанс да намали кислорода 2 пъти
                if (chance%3 < 0.00001)
                    astronaut->breathe();
                astronaut->breathe();
                auto planetItems = &planet.getItems();
                planetItems->erase(std::remove(planetItems->begin(), planetItems->end(), item), planetItems->end()); //премахване на предмета от планетата
            }
            if(killAll) //проверка дали е необходимо дали всички астронавти от експедицията да бъдат убити
            {
                astronaut->name += " - убит/изчезнал";
                astronaut->oxygen = 0;
            }
        }
    }
};
#endif // MISSION_H
