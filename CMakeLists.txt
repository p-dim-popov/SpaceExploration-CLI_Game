project(SpaceExploration-CLI_Game)
cmake_minimum_required(VERSION 3.16)
option(JS_ONLY "Compiles to native JS (No WASM)" ON)

if (EMSCRIPTEN)
    set(CMAKE_CXX_COMPILER "em++")
    set(CMAKE_CXX_FLAGS "-O1 --bind -s ALLOW_MEMORY_GROWTH=1")
endif ()


add_definitions(-std=c++14 -O1)
set(CMAKE_CXX_STANDARD 14)

include_directories(
        include
        /home/pjs/emsdk/upstream/emscripten/system/include)

file(GLOB SOURCES src/*.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/public")

add_executable(a ${SOURCES})
#add_executable(SpaceExploration-CLI_Game
#        include/astronaut.hpp
#        include/astronautRepository.hpp
#        include/backpack.hpp
#        include/biologist.hpp
#        include/controller.hpp
#        include/engine.hpp
#        include/geodesist.hpp
#        include/iController.hpp
#        include/iEngine.hpp
#        include/iMission.hpp
#        include/iRepository.hpp
#        src/main.cpp
#        include/meteorologist.hpp
#        include/mission.hpp
#        include/planet.hpp
#        include/planetRepository.hpp include/JSTestEngine.hpp src/astronaut.cpp src/astronautRepository.cpp src/backpack.cpp src/biologist.cpp src/controller.cpp src/engine.cpp src/geodesist.cpp src/JSTestEngine.cpp src/meteorologist.cpp src/mission.cpp src/planet.cpp src/planetRepository.cpp)
#
if (JS_ONLY)
    message(STATUS "Setting compilation target to native JavaScript")
    set(CMAKE_EXECUTABLE_SUFFIX ".js")
    set_target_properties(a PROPERTIES LINK_FLAGS "-s WASM=0 -s EXPORTED_FUNCTIONS='[_main]' -s NO_EXIT_RUNTIME")
#    else(JS_ONLY)
#        message(STATUS "Setting compilation target to WASM")
#        set(CMAKE_EXECUTABLE_SUFFIX ".wasm.js")
#        set_target_properties(a PROPERTIES LINK_FLAGS "-s WASM=1 -s BINARYEN_METHOD='native-wasm' -s EXPORTED_FUNCTIONS='[_main]' -s NO_EXIT_RUNTIME")
endif (JS_ONLY)