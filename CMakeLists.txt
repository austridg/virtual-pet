cmake_minimum_required(VERSION 3.21)
project(virtual-pet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(virtual-pet
  src/main.cpp
  src/Pet.cpp
  src/Dog.cpp
  src/Cat.cpp
  src/Pet.h
  src/Dog.h
  src/Cat.h
)
find_package(SFML CONFIG REQUIRED COMPONENTS Graphics Window Audio System Network)
target_link_libraries(virtual-pet PRIVATE
  SFML::Graphics SFML::Window SFML::Audio SFML::System SFML::Network
)
if(WIN32)
  add_custom_command(TARGET virtual-pet POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:virtual-pet> $<TARGET_FILE_DIR:virtual-pet>
    COMMAND_EXPAND_LISTS)
endif()
