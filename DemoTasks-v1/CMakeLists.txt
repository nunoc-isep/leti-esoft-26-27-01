cmake_minimum_required(VERSION 3.20)
project(Tasks)
set(CMAKE_CXX_STANDARD 17)

add_executable(Tasks main.cpp)

include_directories(TasksCore)
add_subdirectory(TasksCore)
add_subdirectory(TasksCoreTests)
add_subdirectory(TasksConsoleApp)

target_link_libraries(Tasks TasksCore)