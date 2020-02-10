cmake_minimum_required(VERSION 3.16)
project(SpaceExploration-CLI_Game)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SpaceExploration-CLI_Game
        astronaut.h
        astronautRepository.h
        backpack.h
        biologist.h
        controller.h
        engine.h
        geodesist.h
        iController.h
        iEngine.h
        iMission.h
        iRepository.h
        main.cpp
        meteorologist.h
        mission.h
        planet.h
        planetRepository.h)
