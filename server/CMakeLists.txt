cmake_minimum_required(VERSION 3.22.1)

project(Server)

if (NOT (DEFINED EXECUTABLE_OUTPUT_PATH) OR (EXECUTABLE_OUTPUT_PATH STREQUAL ""))
  SET (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
endif ()


#add_definitions("-Wall -Wsign-conversion -Wextra -Weffc++")

set (impl
	server.cpp
	error_proccessing.cpp
	)

INCLUDE_DIRECTORIES(
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

add_executable(Server ${impl})
