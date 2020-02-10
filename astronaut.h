#ifndef ASTRONAUT_H
#define ASTRONAUT_H
//#include<string>
#include<exception>
#include<stdexcept>
#include<math.h>
#include<vector>
#include"backpack.h"

class Astronaut
{
    friend class Mission;
    std::string name;
    double oxygen;
    Backpack bag;
    void setName(const std::string & value)
    {
        if (value == "" || value == " ")
        {
            throw std::invalid_argument("Astronaut name cannot be null or empty.\n");
        }
        this->name = value;
    }
protected:
    Astronaut(const std::string &name, const double oxygen)
    {
        this->setName(name);
        this->setOxygen(oxygen);
    }
    void setOxygen(const double& value)
    {
        if (value < 0)
        {
            throw new std::invalid_argument("Cannot create Astronaut with negative oxygen!");
        }
        this->oxygen = value;
    }
public:
    Astronaut() {this->name = "";}
    const std::string& getName() const
    {
        return this->name;
    }
    double getOxygen() const
    {
        return this->oxygen;
    }
    bool canBreathe() const
    {
        return this->oxygen > 0;
    }
    Backpack& getBag()
    {
        return this->bag;
    }
    virtual void breathe()
    {
        this->setOxygen(this->oxygen - 10 < 0 ? 0 : this->oxygen - 10);
    }
    bool operator==(const Astronaut& astr) { return !this->name.compare(astr.getName());}
};

#endif // ASTRONAUT_H
