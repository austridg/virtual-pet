cmake_minimum_required(VERSION 3.28)
project(SolbytePet LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(SolPet main.cpp Pet.cpp)
target_compile_features(SolPet PRIVATE cxx_std_23)
target_link_libraries(SolPet PRIVATE SFML::Graphics)
