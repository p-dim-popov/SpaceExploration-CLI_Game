#include <iostream>
#include"engine.h"
using namespace std;

int main()
{
    #ifdef _WIN32
    system("chcp 65001");
    #endif
    srand(time(NULL));
    AstronautRepository astronauts;
    PlanetRepository planets;
    Mission mission;
    Engine eng(cin, cout, astronauts, planets, mission);
    eng.run();
    return 0;
}
