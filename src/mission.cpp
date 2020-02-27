#include "mission.hpp"
#ifdef __EMSCRIPTEN__
#include <emscripten/bind.h>
using namespace emscripten;
#endif
void Mission::explore(Planet &planet, std::vector<Astronaut *> &astronauts, bool killAll) {
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
#ifdef __EMSCRIPTEN__
Mission::~Mission() = default;

EMSCRIPTEN_BINDINGS(mission_class){
    class_<Mission>("Mission")
            .constructor<>()
            ;
}
#endif
