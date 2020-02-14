#include "planet.hpp"

void Planet::setName(const std::string &value) {
    if (value.empty() || value == " ") {
        throw std::invalid_argument("Invalid name!\n");
    }
    this->name = value;
}

Planet::Planet(const std::string &name) { this->setName(name); }

const std::string &Planet::getName() const { return this->name; }

std::vector<std::string> &Planet::getItems() { return this->items; }

bool Planet::operator==(const Planet &planet) { return this->name == planet.getName(); }

Planet::~Planet() = default;
