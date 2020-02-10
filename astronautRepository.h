#ifndef ASTRONAUTREPOSITORY_H
#define ASTRONAUTREPOSITORY_H
#include"iRepository.h"
#include"astronaut.h"
#include<algorithm>
#include<numeric>
class AstronautRepository : public IRepository<Astronaut>
{
    std::vector<Astronaut> astronauts;
public:
    AstronautRepository() = default;
    virtual std::vector<Astronaut>& getModels() override
    {
        return this->astronauts;
    }
    virtual void add(const Astronaut & a) override
    {
        this->astronauts.push_back(a);
    }
    virtual bool remove(const Astronaut & a) override
    {
        auto countBefore = this->astronauts.size();
        astronauts.erase(std::remove(astronauts.begin(), astronauts.end(), a), astronauts.end());
        return this->astronauts.size() < countBefore;
    }
};
#endif // ASTRONAUTREPOSITORY_H
