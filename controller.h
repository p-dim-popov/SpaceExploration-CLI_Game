#ifndef CONTROLLER_H
#define CONTROLLER_H

#include"iController.h"
#include"astronaut.h"
#include"biologist.h"
#include"meteorologist.h"
#include"geodesist.h"
#include"mission.h"
#include"planet.h"
#include"planetRepository.h"
#include"astronautRepository.h"
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
    Controller(IRepository<Astronaut> &astronauts, IRepository<Planet> &planets, IMission &mission) {
        this->astronauts = &astronauts;
        this->planets = &planets;
        this->mission = &mission;
    }

    // IController interface
public:
    virtual std::string addAstronaut(const std::string &type, const std::string &astronautName) override {
        Astronaut *astronaut;
        std::string bg_type;
        if (type == "биолог" || type == "biologist") {
            bg_type = "биолог";
            astronaut = new Biologist(astronautName);
        } else if (type == "геодезист" || type == "geodesist") {
            bg_type = "геодезист";
            astronaut = new Geodesist(astronautName);
        } else if (type == "метеоролог" || type == "meteorologist") {
            bg_type = "метеоролог";
            astronaut = new Meteorologist(astronautName);
        } else throw std::invalid_argument("Няма такъв вид астронавт!\n");

        this->astronauts->add(*astronaut);

        return astronautName + " беше добавен, длъжност - " + bg_type + '\n';
    }

    virtual std::string addPlanet(const std::string &planetName, std::vector<std::string> &items) override {
        auto planet = new Planet(planetName);
        for (const auto &item : items) {
            planet->getItems().push_back(item);
        }
        this->planets->add(*planet);
        return "Успешно добавена планета - " + planetName + '\n';
    }

    virtual std::string retireAstronaut(const std::string &astronautName) override {
        auto astronautToRemove = std::find_if(this->astronauts->getModels().begin(),
                                              this->astronauts->getModels().end(),
                                              [&astronautName](const Astronaut &a) {
                                                  return astronautName == a.getName();
                                              });
        if (astronautToRemove != this->astronauts->getModels().end())
            if (this->astronauts->remove(*astronautToRemove))
                return "Успешно пенсиониран астронавт - " + astronautName + '\n';
        return "Няма такъв астронавт...\n";
    }

    virtual std::string explorePlanet(const std::string &planetName) override {
        std::shuffle(this->astronauts->getModels().begin(), this->astronauts->getModels().end(),
                     std::mt19937(std::random_device()()));
        std::vector<Astronaut *> suitableAstronauts;
        for (auto &astronaut : astronauts->getModels()) {
            if (astronaut.getOxygen() > 20 && !astronaut.getBag().isFull()) {
                suitableAstronauts.push_back(&astronaut);
            }
        }
        if (suitableAstronauts.empty())
            throw std::logic_error("Няма годни астронавти за експедиция...\n");
        auto planet = std::find_if(this->planets->getModels().begin(), this->planets->getModels().end(),
                                   [&planetName](const Planet &p) { return p.getName() == planetName; });
        if (planet == this->planets->getModels().end()) throw std::invalid_argument("Няма планета с такова име!");

        bool killAll = (1 + rand() % 100) > 49;
        this->mission->explore(*planet, suitableAstronauts, killAll);
        this->exploredPlanets.insert(planetName);
        auto deadAstronauts = std::count_if(suitableAstronauts.begin(), suitableAstronauts.end(),
                                            [](Astronaut *astronaut) { return !astronaut->canBreathe(); });
        return "Експедиция на планетата " + planetName + " завърши! Загинали астронавти: " +
               std::to_string(deadAstronauts) + '\n';
    }

    virtual std::string report() override {
        std::stringstream ss;
        ss << this->exploredPlanets.size() << " планети бяха изследвани!\n"
           << "Информация за астронавтите:\n";
        for (auto &astronaut : this->astronauts->getModels()) {
            std::string bagItems =
                    std::accumulate(std::begin(astronaut.getBag().getItems()), std::end(astronaut.getBag().getItems()),
                                    std::string(),
                                    [](std::string &ss, std::string &s) {
                                        return ss.empty() ? s : ss.append(", ").append(s);
                                    });
            bagItems = !bagItems.empty() ? bagItems : "няма";
            ss << "## Име: " << astronaut.getName() << '\n'
               << "## Оставащ кислород: " << astronaut.getOxygen() << '\n'
               << "## Предмети: " << bagItems << '\n';
        }
        ss << std::endl;
        return ss.str().substr(0, ss.str().length() - 1);
    }
};

#endif // CONTROLLER_H
