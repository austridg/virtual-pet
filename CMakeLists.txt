cmake_minimum_required(VERSION 3.21)
project(virtual-pet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(virtual-pet
  main.cpp
  Pet.cpp
  Pet.h
)

find_package(SFML 2.6 CONFIG REQUIRED COMPONENTS system window graphics audio)
target_link_libraries(virtual-pet PRIVATE sfml-system sfml-window sfml-graphics sfml-audio)

if(WIN32)
  add_custom_command(TARGET virtual-pet POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:virtual-pet> $<TARGET_FILE_DIR:virtual-pet>
    COMMAND_EXPAND_LISTS)
endif()