#ifndef PLANETREPOSITORY_H
#define PLANETREPOSITORY_H
#include"iRepository.h"
#include"planet.h"
#include<algorithm>
class PlanetRepository : public IRepository<Planet>
{
    std::vector<Planet> planets;
public:
    PlanetRepository() = default;
    virtual std::vector<Planet>& getModels() override
    {
        return this->planets;
    }
    virtual void add(const Planet& planet) override
    {
        planets.push_back(planet);
    }
    virtual bool remove(const Planet& planet) override
    {
        auto countBefore = this->planets.size();
        planets.erase(std::remove(planets.begin(), planets.end(), planet), planets.end());
        return countBefore < this->planets.size();
    }
};
#endif // PLANETREPOSITORY_H
