#include "JSTestEngine.hpp"
#include"engine.hpp"
#include <iostream>

using namespace std;

int main() {
#ifdef _WIN32
    system("chcp 65001");
#endif
    srand(time(nullptr));
#ifndef __EMSCRIPTEN__
    AstronautRepository astronauts;
    PlanetRepository planets;
    Mission mission;
    Engine eng(cin, cout, astronauts, planets, mission);
    eng.run();
#endif
    return 0;
}
