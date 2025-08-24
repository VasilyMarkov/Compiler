cmake_minimum_required(VERSION 3.21)
project(Compiler)

find_package(FLEX REQUIRED)

flex_target(scanner
  lexer.l
  ${CMAKE_CURRENT_BINARY_DIR}/lexer.cc
)

add_executable(Compiler main.cpp ${FLEX_scanner_OUTPUTS})

target_include_directories(Compiler PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(Compiler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Compiler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)