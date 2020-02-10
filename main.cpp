#include <iostream>
#include"engine.h"
using namespace std;

int main()
{
    ::setlocale( LC_ALL , "russian_russia.866" );
    srand(time(NULL));
    AstronautRepository astronauts;
    PlanetRepository planets;
    Mission mission;
    Engine eng(cin, cout, astronauts, planets, mission);
    eng.run();
    return 0;
}
