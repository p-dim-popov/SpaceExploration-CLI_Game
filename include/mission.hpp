#ifndef MISSION_H
#define MISSION_H
#include"iMission.hpp"
#include<algorithm>
#include"planetRepository.hpp"
#include"astronautRepository.hpp"
#include<chrono>
#include<ctime>

class Mission : public IMission
{
public:
    Mission() = default;
    void explore(Planet & planet, std::vector<Astronaut*>& astronauts, bool killAll) override;

    ~Mission() override;
};

#endif // MISSION_H
