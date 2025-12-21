cmake_minimum_required(VERSION 3.5)

project(AML_Test)

find_package(Catch2 REQUIRED)

add_executable(${PROJECT_NAME}
  AMLVector3Test.cpp
  )

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  Catch2::Catch2WithMain
  AttitudeMathLib
)

add_test(NAME mytest01 COMMAND ${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME}
  DESTINATION ${CMAKE_BINARY_DIR}/bin
)
