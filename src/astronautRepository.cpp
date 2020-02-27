#include "astronautRepository.hpp"
#ifdef __EMSCRIPTEN__
#include <emscripten/bind.h>
using namespace emscripten;
#endif
std::vector<Astronaut> &AstronautRepository::getModels() {
    return this->astronauts;
}

void AstronautRepository::add(const Astronaut &a) {
    this->astronauts.push_back(a);
}

bool AstronautRepository::remove(const Astronaut &a) {
    auto countBefore = this->astronauts.size();
    astronauts.erase(std::remove(astronauts.begin(), astronauts.end(), a), astronauts.end());
    return this->astronauts.size() < countBefore;
}

AstronautRepository::~AstronautRepository() = default;
#ifdef __EMSCRIPTEN__
EMSCRIPTEN_BINDINGS(astronaut_repo_class){
    class_<AstronautRepository>("AstronautRepository")
            .constructor<>()
            ;
}
#endif
