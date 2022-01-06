cmake_minimum_required( VERSION 3.20 )

project( PizzAppTest CXX )

set( CMAKE_CXX_STANDARD 17            )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_INCLUDE_CURRENT_DIR ON     )

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/../src )
include_directories( test                               )

enable_testing()
find_package(GTest REQUIRED)

set( TARGET_NAME PizzAppTest )

add_executable( ${TARGET_NAME} GTest.h main.cpp)
target_link_libraries( ${TARGET_NAME} PRIVATE GTest::gtest GTest::gmock )

add_test(NAME PizzApp.UnitTests COMMAND ${TARGET_NAME})
