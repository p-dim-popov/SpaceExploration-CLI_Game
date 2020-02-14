#include "meteorologist.hpp"

Meteorologist::Meteorologist(const std::string &name) : Astronaut(name, meteo_init_oxygen) {}

Meteorologist::~Meteorologist() = default;
