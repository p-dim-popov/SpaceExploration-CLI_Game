#ifndef PLANET_H
#define PLANET_H

#include<string>
#include<vector>
#include<stdexcept>

class Planet {
    std::string name;
    std::vector<std::string> items;

    void setName(const std::string &value) {
        if (value.empty() || value == " ") {
            throw std::invalid_argument("Invalid name!\n");
        }
        this->name = value;
    }

public:
    explicit Planet(const std::string &name) { this->setName(name); }

    const std::string &getName() const { return this->name; }

    std::vector<std::string> &getItems() { return this->items; }

    bool operator==(const Planet &planet) { return this->name == planet.getName(); }
};

#endif // PLANET_H
