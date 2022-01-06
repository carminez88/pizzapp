cmake_minimum_required( VERSION 3.20 )

set(PIZZAPP_VERSION 0.0.0.0)
add_compile_definitions(VERSION="${PIZZAPP_VERSION}")
add_compile_definitions(PROGRAM_NAME="PizzApp") 

project( PizzApp VERSION ${PIZZAPP_VERSION} LANGUAGES CXX )

set( CMAKE_DISABLE_IN_SOURCE_BUILD ON )

set( CMAKE_CXX_STANDARD 17            )
set( CMAKE_CXX_STANDARD_REQUIRED True )
set( CMAKE_INCLUDE_CURRENT_DIR ON     )

set( CMAKE_AUTOMOC ON )
set( CMAKE_AUTOUIC ON )
set( CMAKE_AUTORCC ON )

include( cmake/FindDependencies.cmake )
include( cmake/Sources.cmake          )

option( BUILD_TESTS "Build tests" ON )
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

set( TARGET_NAME PizzApp )

add_executable( ${TARGET_NAME} ${PIZZAPP_SRCS} )

target_link_libraries( ${TARGET_NAME} PUBLIC ${QT_LIBS} )

if(LINUX)
    target_link_libraries( ${TARGET_NAME} PRIVATE Threads::Threads ${CMAKE_DL_LIBS} )
endif()
