#ifndef PLANETREPOSITORY_H
#define PLANETREPOSITORY_H
#include"iRepository.h"
#include"planet.h"
#include<algorithm>
class PlanetRepository : public IRepository<Planet>
{
    Planet nullPlanet;
    std::vector<Planet> planets;
public:
    PlanetRepository() {}
    virtual std::vector<Planet>& getModels() override
    {
        return this->planets;
    }
    virtual void add(const Planet& planet) override
    {
        planets.push_back(planet);
    }
//    const Planet& findByName(const std::string & name)
//    {
//        for(unsigned long i = 0; i < this->planets.size(); i++)
//        {
//            if(this->planets[i].getName() == name)
//            {
//                return this->planets[i];
//            }
//        }
//        return nullPlanet;
//    }
    virtual bool remove(const Planet& planet) override
    {
        auto countBefore = this->planets.size();
        planets.erase(std::remove(planets.begin(), planets.end(), planet), planets.end());
        return countBefore < this->planets.size();
    }
};
#endif // PLANETREPOSITORY_H
