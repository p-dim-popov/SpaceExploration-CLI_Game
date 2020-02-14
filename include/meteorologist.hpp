#ifndef METEOROLOGIST_H
#define METEOROLOGIST_H
#include "astronaut.hpp"

const int meteo_init_oxygen = 90;
class Meteorologist : public Astronaut
{
public:
    explicit Meteorologist(const std::string & name);

    ~Meteorologist() override;
};

#endif // METEOROLOGIST_H
