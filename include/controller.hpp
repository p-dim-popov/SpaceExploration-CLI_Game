#ifndef CONTROLLER_H
#define CONTROLLER_H

#include"iController.hpp"
#include"astronaut.hpp"
#include"biologist.hpp"
#include"meteorologist.hpp"
#include"geodesist.hpp"
#include"mission.hpp"
#include"planet.hpp"
#include"planetRepository.hpp"
#include"astronautRepository.hpp"
#include <random>
#include<vector>
#include<algorithm>
#include<sstream>
#include<numeric>
#include<cmath>
#include<ctime>
#include<set>

class Controller : public IController {
    IRepository<Astronaut> *astronauts;
    IRepository<Planet> *planets;
    IMission *mission;
    std::set<std::string> exploredPlanets;

public:
    Controller(IRepository<Astronaut> &astronauts, IRepository<Planet> &planets, IMission &mission);

    std::string addAstronaut(const std::string &type, const std::string &astronautName) override;
    std::string addPlanet(const std::string &planetName, std::vector<std::string> &items) override;
    std::string retireAstronaut(const std::string &astronautName) override;
    std::string explorePlanet(const std::string &planetName) override;
    std::string report() override;

    ~Controller() override;
};

#endif // CONTROLLER_H
