#include "JSTestEngine.hpp"
//#include"engine.hpp"
#include <iostream>

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
//    Engine eng(cin, cout, astronauts, planets, mission);
//    eng.run();
    JSTestEngine eng(astronauts, planets, mission);
    while (true){
        string input;
        getline(cin, input);
        string output = eng.action(input);
        if (output == "Край" || output == "End") break;
        cout << output;
    }
    return 0;
}
