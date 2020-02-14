#ifndef ASTRONAUT_H
#define ASTRONAUT_H

#include<stdexcept>
#include<cmath>
#include<vector>
#include"backpack.hpp"

class Astronaut {
    friend class Mission;
    std::string name;
    double oxygen;
    Backpack bag;

    void setName(const std::string &value);
protected:
    Astronaut(const std::string &name, double oxygen);
    void setOxygen(const double &value);
public:
    const std::string &getName() const;
    double getOxygen() const;
    bool canBreathe() const;
    Backpack &getBag();
    virtual void breathe();
    bool operator==(const Astronaut &a);

    virtual ~Astronaut();
};

#endif // ASTRONAUT_H
