#ifndef BIOLOGIST_H
#define BIOLOGIST_H
#include "astronaut.hpp"

const int bio_init_oxygen = 70;
class Biologist : public Astronaut
{
public:
    explicit Biologist(const std::string& name);;

    void breathe() override;

    ~Biologist() override;
};

#endif // BIOLOGIST_H
