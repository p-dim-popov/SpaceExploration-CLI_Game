#include "astronaut.hpp"

void Astronaut::setName(const std::string &value) {
    if (value.empty() || value == " ") {
        throw std::invalid_argument("Името на астронавт не може да бъде празно!\n");
    }
    this->name = value;
}

Astronaut::Astronaut(const std::string &name, const double oxygen) {
    this->setName(name);
    this->setOxygen(oxygen);
}

void Astronaut::setOxygen(const double &value) {
    if (value < 0) {
        throw std::invalid_argument("Не може да се зададе негативна стойност за кислород!\n");
    }
    this->oxygen = value;
}

const std::string &Astronaut::getName() const {
    return this->name;
}

double Astronaut::getOxygen() const {
    return this->oxygen;
}

bool Astronaut::canBreathe() const {
    return this->oxygen > 0;
}

Backpack &Astronaut::getBag() {
    return this->bag;
}

void Astronaut::breathe() {
    this->setOxygen(this->oxygen - 10 < 0 ? 0 : this->oxygen - 10);
}

bool Astronaut::operator==(const Astronaut &a) { return this->name == a.getName(); }

Astronaut::~Astronaut() = default;
