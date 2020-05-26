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

