#include "JSTestEngine.hpp"

JSTestEngine::JSTestEngine(IRepository<Astronaut> &astronauts, IRepository<Planet> &planets, IMission &mission) {
    this->astronauts = &astronauts;
    this->planets = &planets;
    this->mission = &mission;
    this->c = new Controller(*this->astronauts, *this->planets, *this->mission);
}

void JSTestEngine::run() {
}

std::string JSTestEngine::action(const std::string &input) {
    if (input == "Край")
        return "Край";
    if (input == "End")
        return "End";

    std::vector<std::string> args;
    std::stringstream split_stream(input);
    std::string token;
    while (std::getline(split_stream, token, ' ')) {
        args.push_back(token);
    }
    auto command = args[0];
    try {
        if (command == ("ДобавиАстронавт") || command == ("AddAstronaut")) {
            return c->addAstronaut(args[1], args[2]);
        } else if (command == ("ДобавиПланета") || command == ("AddPlanet")) {
            std::vector<std::string> items;
            if (args.size() == 3) {
                std::stringstream split_stream_items(args[2]);
                std::string item_token;
                while (std::getline(split_stream_items, item_token, ',')) {
                    items.push_back(item_token);
                }
            }
            return c->addPlanet(args[1], items);
        } else if (command == ("ПенсионирайАстронавт") || command == ("RetireAstronaut")) {
            return c->retireAstronaut(args[1]);
        } else if (command == ("ИзследвайПланета") || command == ("ExplorePlanet")) {
            return c->explorePlanet(args[1]);
        } else if (command == ("Отчет") || command == ("Report")) {
            return c->report();
        } else return "Грешна команда";
    }
    catch (std::exception &e) {
        return e.what();
    }
}

JSTestEngine::~JSTestEngine() = default;
