cmake_minimum_required(VERSION 3.0)
project(Virtual-Harem)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

add_executable(Virtual-Harem ${SOURCES})

file(GLOB_RECURSE HEADER_DIRS CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*")
target_include_directories(Virtual-Harem PRIVATE ${HEADER_DIRS})