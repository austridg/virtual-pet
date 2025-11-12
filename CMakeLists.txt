cmake_minimum_required(VERSION 3.21)
project(virtual-pet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# if your sources are in src/, list them here
add_executable(virtual-pet
  src/main.cpp
  src/Pet.cpp
  src/Dog.cpp
  src/Cat.cpp
  src/Pet.h
  src/Dog.h
  src/Cat.h
)

# SFML 3 targets via vcpkg
find_package(SFML CONFIG REQUIRED COMPONENTS Graphics Window Audio System Network)
target_link_libraries(virtual-pet PRIVATE
  SFML::Graphics SFML::Window SFML::Audio SFML::System SFML::Network
)

# copy dependent DLLs beside the exe on Windows after build
if(WIN32)
  add_custom_command(TARGET virtual-pet POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:virtual-pet> $<TARGET_FILE_DIR:virtual-pet>
    COMMAND_EXPAND_LISTS)
endif()
