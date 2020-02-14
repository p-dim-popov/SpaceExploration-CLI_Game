#ifndef GEODESIST_H
#define GEODESIST_H
#include "astronaut.hpp"

const int geo_init_oxygen = 65;

class Geodesist : public Astronaut
{
public:
    explicit Geodesist(const std::string & name);

    ~Geodesist() override;
};
#endif // GEODESIST_H
