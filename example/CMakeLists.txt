cmake_minimum_required(VERSION 3.0.0)
project(example VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../ ${CMAKE_CURRENT_SOURCE_DIR}/libbuild EXCLUDE_FROM_ALL)

add_executable(example main.cpp)

target_link_libraries(example PRIVATE notifier)


