#ifndef ASTRONAUTREPOSITORY_H
#define ASTRONAUTREPOSITORY_H
#include"iRepository.hpp"
#include"astronaut.hpp"
#include<algorithm>
#include<numeric>
class AstronautRepository : public IRepository<Astronaut>
{
    std::vector<Astronaut> astronauts;
public:
    AstronautRepository() = default;
    std::vector<Astronaut>& getModels() override;
    void add(const Astronaut & a) override;
    bool remove(const Astronaut & a) override;

    ~AstronautRepository() override;
};
#endif // ASTRONAUTREPOSITORY_H
