cmake_minimum_required(VERSION 3.18)

set(PROJECT_NAME "morse")
set(CMAKE_CXX_STANDARD 17)

find_package(Boost 1.74 REQUIRED COMPONENTS system)
IF(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
ELSE()
    message(FATAL "${CMAKE_SOURCE_DIR}/../include")
ENDIF(Boost_FOUND)

add_executable(${PROJECT_NAME} src/main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)

# tests
find_package(Catch2 2 REQUIRED)

# These tests can use the Catch2-provided main
add_executable(tests tests/tests.cpp)
target_include_directories(tests PUBLIC include)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)