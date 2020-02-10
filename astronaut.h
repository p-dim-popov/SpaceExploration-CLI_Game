#ifndef ASTRONAUT_H
#define ASTRONAUT_H

#include<stdexcept>
#include<cmath>
#include<vector>
#include"backpack.h"

class Astronaut {
    friend class Mission;

    std::string name;
    double oxygen;
    Backpack bag;

    void setName(const std::string &value) {
        if (value.empty() || value == " ") {
            throw std::invalid_argument("Името на астронавт не може да бъде празно!\n");
        }
        this->name = value;
    }

protected:
    Astronaut(const std::string &name, const double oxygen) {
        this->setName(name);
        this->setOxygen(oxygen);
    }

    void setOxygen(const double &value) {
        if (value < 0) {
            throw std::invalid_argument("Не може да се зададе негативна стойност за кислород!\n");
        }
        this->oxygen = value;
    }

public:
    const std::string &getName() const {
        return this->name;
    }

    double getOxygen() const {
        return this->oxygen;
    }

    bool canBreathe() const {
        return this->oxygen > 0;
    }

    Backpack &getBag() {
        return this->bag;
    }

    virtual void breathe() {
        this->setOxygen(this->oxygen - 10 < 0 ? 0 : this->oxygen - 10);
    }

    bool operator==(const Astronaut &a) { return this->name == a.getName(); }
};

#endif // ASTRONAUT_H
