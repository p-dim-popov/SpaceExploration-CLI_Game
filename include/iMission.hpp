#ifndef IMISSION_H
#define IMISSION_H
#include "planet.hpp"
#include "astronaut.hpp"
#include <vector>
class IMission
{
public:
    virtual void explore(Planet&, std::vector<Astronaut*>&, bool) = 0;

    virtual ~IMission() = default;
};
#endif // IMISSION_H
