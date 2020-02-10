#ifndef GEODESIST_H
#define GEODESIST_H
#include "astronaut.h"

const int geo_init_oxygen = 65;

class Geodesist : public Astronaut
{
public:
    Geodesist(const std::string & name) : Astronaut(name, geo_init_oxygen) {}
};
#endif // GEODESIST_H
