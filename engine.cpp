#include "engine.hpp"

Engine::Engine(std::istream &in, std::ostream &out, IRepository<Astronaut> &astronauts, IRepository<Planet> &planets,
               IMission &mission) {
    this->in = &in;
    this->out = &out;
    this->astronauts = &astronauts;
    this->planets = &planets;
    this->mission = &mission;
}

void Engine::run() {
    Controller c(*this->astronauts, *this->planets, *this->mission);

    while (true)
    {
        std::string input;
        std::getline(std::cin, input);
        if(input == ("Край") || input == ("End"))
            break;
        std::vector<std::string> args;
        std::stringstream split_stream(input);
        std::string token;
        while (std::getline(split_stream, token, ' ')) {
            args.push_back(token);
        }
        auto command = args[0];
        try {
            if(command == ("ДобавиАстронавт") || command == ("AddAstronaut"))
            {
                *this->out << c.addAstronaut(args[1], args[2]);
            }
            else if(command == ("ДобавиПланета") || command == ("AddPlanet"))
            {
                std::vector<std::string> items;
                if (args.size() == 3)
                {
                    std::stringstream split_stream_items(args[2]);
                    std::string item_token;
                    while (std::getline(split_stream_items, item_token, ',')) {
                        items.push_back(item_token);
                    }
                }
                *this->out << c.addPlanet(args[1], items);
            }
            else if(command == ("ПенсионирайАстронавт") || command == ("RetireAstronaut"))
            {
                *this->out << c.retireAstronaut(args[1]);
            }
            else if(command == ("ИзследвайПланета") || command == ("ExplorePlanet"))
            {
                *this->out << c.explorePlanet(args[1]);
            }
            else if(command == ("Отчет") || command == ("Report"))
            {
                *this->out << c.report();
            }
            else continue;
        }
        catch (std::exception& e)
        {
            *this->out << e.what();
        }
    }
}

Engine::~Engine() = default;
