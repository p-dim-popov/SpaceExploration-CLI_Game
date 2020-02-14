#ifndef PLANETREPOSITORY_H
#define PLANETREPOSITORY_H
#include"iRepository.hpp"
#include"planet.hpp"
#include<algorithm>
class PlanetRepository : public IRepository<Planet>
{
    std::vector<Planet> planets;
public:
    PlanetRepository() = default;
    std::vector<Planet>& getModels() override;
    void add(const Planet& planet) override;
    bool remove(const Planet& planet) override;

    ~PlanetRepository() override;
};
#endif // PLANETREPOSITORY_H
