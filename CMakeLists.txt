cmake_minimum_required(VERSION 3.12)
project(Torch)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Find the SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Set the source files for your application
set(SOURCES main.cpp)

# Create the executable
add_executable(Torch ${SOURCES})

# Link against the SDL2 library
target_link_libraries(SDLExample ${SDL2_LIBRARIES})
