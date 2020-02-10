#ifndef IMISSION_H
#define IMISSION_H
#include "planet.h"
#include "astronaut.h"
#include <vector>
#include"astronautRepository.h"
class IMission
{
public:
    virtual void explore(Planet&, std::vector<Astronaut*>&, bool) = 0;
};
#endif // IMISSION_H
