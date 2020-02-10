#ifndef BIOLOGIST_H
#define BIOLOGIST_H
#include "astronaut.h"

const int bio_init_oxygen = 70;
class Biologist : public Astronaut
{
public:
    explicit Biologist(const std::string& name): Astronaut(name, bio_init_oxygen) {};

    virtual void breathe() override
    {
        this->setOxygen((this->getOxygen() - 2) < 0 ? 0 : this->getOxygen() - 2);
    }
};

#endif // BIOLOGIST_H
