cmake_minimum_required(VERSION 3.5)
project(AttitudeMathLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++20")

set(SRC_CPP_AML
  AMLVector3.cpp
)

add_library(
  ${PROJECT_NAME} STATIC
  ${SRC_CPP_AML}
)

target_include_directories(
  ${PROJECT_NAME} PUBLIC
  ${PROJECT_SOURCE_DIR}
)
