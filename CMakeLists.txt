cmake_minimum_required(VERSION 3.0.0)
project(notifier VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB src
    "src/*.cpp"
    "src/*/*.cpp"
    )

add_library(notifier STATIC ${src})

if(UNIX)

find_package(PkgConfig REQUIRED)
pkg_check_modules(LibNotify REQUIRED libnotify)
pkg_check_modules(GLIB REQUIRED glib-2.0)

target_link_libraries(notifier INTERFACE ${GLIB_LIBRARIES} ${LibNotify_LIBRARIES})
target_include_directories(notifier SYSTEM PUBLIC ${GLIB_INCLUDE_DIRS} ${LibNotify_INCLUDE_DIRS}})

endif()

target_include_directories(notifier SYSTEM PUBLIC "include")





