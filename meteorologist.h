#ifndef METEOROLOGIST_H
#define METEOROLOGIST_H
#include "astronaut.h"

const int meteorologist_init_oxygen = 90;
class Meteorologist : public Astronaut
{
public:
    explicit Meteorologist(const std::string & name) : Astronaut(name, meteorologist_init_oxygen) {}
};

#endif // METEOROLOGIST_H
