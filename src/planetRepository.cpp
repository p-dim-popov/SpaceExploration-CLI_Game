#include "planetRepository.hpp"
#ifdef __EMSCRIPTEN__
#include <emscripten/bind.h>
using namespace emscripten;
#endif
std::vector<Planet> &PlanetRepository::getModels() {
    return this->planets;
}

void PlanetRepository::add(const Planet &planet) {
    planets.push_back(planet);
}

bool PlanetRepository::remove(const Planet &planet) {
    auto countBefore = this->planets.size();
    planets.erase(std::remove(planets.begin(), planets.end(), planet), planets.end());
    return countBefore < this->planets.size();
}

PlanetRepository::~PlanetRepository() = default;
#ifdef __EMSCRIPTEN__
EMSCRIPTEN_BINDINGS(planet_repo_class){
    class_<PlanetRepository>("PlanetRepository")
            .constructor<>()
            ;
}
#endif
