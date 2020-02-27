project(SpaceExploration-CLI_Game)
cmake_minimum_required(VERSION 3.16)

if (EMSCRIPTEN)
    option(JS_ONLY "Compiles to native JS (No WASM)" ON)
    set(CMAKE_CXX_COMPILER "em++")
    set(CMAKE_CXX_FLAGS "-O1 --bind -s ALLOW_MEMORY_GROWTH=1")
    add_definitions(-std=c++14 -O1)
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED 17)

include_directories(include)
if (EMSCRIPTEN)
    include_directories(/home/pjs/emsdk/upstream/emscripten/system/include)
endif ()

file(GLOB SOURCES src/*.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/public")

add_executable(a ${SOURCES})

if (EMSCRIPTEN)
    if (JS_ONLY)
        message(STATUS "Setting compilation target to native JavaScript")
        set(CMAKE_EXECUTABLE_SUFFIX ".js")
        set_target_properties(a PROPERTIES LINK_FLAGS "-s WASM=0 -s EXPORTED_FUNCTIONS='[_main]' -s NO_EXIT_RUNTIME")
    else (JS_ONLY)
        message(STATUS "Setting compilation target to WASM")
        set(CMAKE_EXECUTABLE_SUFFIX ".wasm.js")
        set_target_properties(a PROPERTIES LINK_FLAGS "-s WASM=1 -s BINARYEN_METHOD='native-wasm' -s EXPORTED_FUNCTIONS='[_main]' -s NO_EXIT_RUNTIME")
    endif (JS_ONLY)

endif ()
