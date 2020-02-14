#ifndef ENGINE_H
#define ENGINE_H
#include"iEngine.hpp"
#include<iostream>
#include<istream>
#include<ostream>
#include<fstream>
#include"controller.hpp"

class Engine : public IEngine
{
    std::istream *in;
    std::ostream *out;
    IRepository<Astronaut>* astronauts;
    IRepository<Planet>* planets;
    IMission* mission;

public:
    Engine(std::istream& in, std::ostream& out, IRepository<Astronaut>& astronauts, IRepository<Planet>& planets, IMission& mission);
    void run() override;

    ~Engine() override;
};
#endif // ENGINE_H
