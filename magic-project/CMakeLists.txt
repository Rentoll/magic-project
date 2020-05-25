cmake_minimum_required(VERSION 2.7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(magic C CXX) 

find_package(Curses REQUIRED)


add_executable(magic main.c
		enemyAi.c
		init.c
		magic.c
		nameGenerator.c
		nextLevel.c
		stage.c)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE ${CURSES_LIBRARIES})

#enable_testing()

#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})

#add_executable(magic_test test.cpp main.c
#		enemyAi.c
#		init.c
#		magic.c
#		nameGenerator.c
#		nextLevel.c
#		stage.c)
#target_include_directories(magic_test PRIVATE ${CURSES_INCLUDE_DIR})
#target_link_libraries(magic_test PRIVATE ${CURSES_LIBRARIES})
#target_link_libraries(magic_test ${GTEST_LIBRARIES} pthread)

#add_test(NAME magicTest COMMAND magic_test)
