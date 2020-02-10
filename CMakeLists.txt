cmake_minimum_required(VERSION 3.16)
project(csharp_kursow_proekt_test01)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(csharp_kursow_proekt_test01
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
