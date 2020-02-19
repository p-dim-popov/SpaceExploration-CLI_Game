#ifndef SPACEEXPLORATION_CLI_GAME_JSTESTENGINE_HPP
#define SPACEEXPLORATION_CLI_GAME_JSTESTENGINE_HPP

#include"iEngine.hpp"
#include<iostream>
#include<istream>
#include<ostream>
#include<fstream>
#include"controller.hpp"

class JSTestEngine : public IEngine {
    IRepository<Astronaut> *astronauts;
    IRepository<Planet> *planets;
    IMission *mission;
    IController *c;
public:
    JSTestEngine(AstronautRepository &astronauts, PlanetRepository &planets, Mission &mission);
    JSTestEngine(IRepository<Astronaut> &astronauts, IRepository<Planet> &planets, IMission &mission);

    void run() override;
    std::string action(const std::string& input);

    ~JSTestEngine() override;
};

#endif //SPACEEXPLORATION_CLI_GAME_JSTESTENGINE_HPP
