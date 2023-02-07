set(CMAKE_C_COMPILER "gcc")
cmake_minimum_required(VERSION 3.25.2)
project(oioi)

if (APPLE)
  INCLUDE_DIRECTORIES(/opt/homebrew/include)
  set(CMAKE_GENERATOR_PLATFORM APPLE)
  set(CMAKE_LIBRARY_PATH /opt/homebrew/lib)
endif(APPLE)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(GL_SILENCE_DEPRECATION)
add_definitions(-Wdeprecated-declarations)

add_executable(oioi main.c shader.h)
target_link_libraries(oioi ${SDL2_LIBRARIES})
