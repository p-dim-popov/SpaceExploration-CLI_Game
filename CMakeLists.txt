cmake_minimum_required(VERSION 3.16)
project(SpaceExploration-CLI_Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SpaceExploration-CLI_Game
        astronaut.hpp
        astronautRepository.hpp
        backpack.hpp
        biologist.hpp
        controller.hpp
        engine.hpp
        geodesist.hpp
        iController.hpp
        iEngine.hpp
        iMission.hpp
        iRepository.hpp
        main.cpp
        meteorologist.hpp
        mission.hpp
        planet.hpp
        planetRepository.hpp JSTestEngine.hpp astronaut.cpp astronautRepository.cpp backpack.cpp biologist.cpp controller.cpp engine.cpp geodesist.cpp JSTestEngine.cpp meteorologist.cpp mission.cpp planet.cpp planetRepository.cpp)
