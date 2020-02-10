#ifndef METEOROLOGIST_H
#define METEOROLOGIST_H
#include "astronaut.h"

const int meteo_init_oxygen = 90;
class Meteorologist : public Astronaut
{
public:
    Meteorologist(const std::string & name) : Astronaut(name, meteo_init_oxygen) {}
};

#endif // METEOROLOGIST_H
