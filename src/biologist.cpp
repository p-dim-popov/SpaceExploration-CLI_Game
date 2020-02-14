#include "biologist.hpp"

Biologist::Biologist(const std::string &name) : Astronaut(name, bio_init_oxygen) {}

void Biologist::breathe() {
    this->setOxygen((this->getOxygen() - 2) < 0 ? 0 : this->getOxygen() - 2);
}

Biologist::~Biologist() = default;
