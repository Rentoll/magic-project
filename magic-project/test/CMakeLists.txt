cmake_minimum_required(VERSION 2.7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(magic C CXX) 

find_package(Curses REQUIRED)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(magic_test ../test.cpp 
		../enemyAi.c
		../init.c
		../magic.c
		../nameGenerator.c
		../nextLevel.c
		../stage.c)
target_include_directories(magic_test PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(magic_test PRIVATE ${CURSES_LIBRARIES})
target_link_libraries(magic_test ${GTEST_LIBRARIES} pthread)

add_test(NAME magicTest COMMAND magic_test)
