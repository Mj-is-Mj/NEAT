cmake_minimum_required(VERSION 3.5)

PROJECT( neat )

FILE(GLOB neat_sources src/*.cpp)

ADD_EXECUTABLE( neat ${neat_sources} )
target_include_directories(neat PRIVATE include)