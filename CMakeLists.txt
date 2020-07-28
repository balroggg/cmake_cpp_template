cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(
            FATAL_ERROR
            "In-source builds not allowed. Please make a new directory and run CMake from there. You may need to remove CMakeCache.txt."
    )
endif ()

project(hello_world)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

find_program(
        clang_tidy
        NAMES clang-tidy
        DOC "Clang kinda linter")

message("\n#####################################################\n")
message("CMAKE_BUILD_TYPE:\t${CMAKE_BUILD_TYPE}")
message("CMAKE_INSTALL_PREFIX:\t${CMAKE_INSTALL_PREFIX}")
message("CMAKE_BINARY_DIR:\t${CMAKE_BINARY_DIR}")
message("CMAKE_SYSTEM_NAME:\t${CMAKE_SYSTEM_NAME}")
message("CMAKE_GENERATOR:\t${CMAKE_GENERATOR}")
message("CMAKE_C_COMPILER:\t${CMAKE_C_COMPILER}")
message("CMAKE_CXX_COMPILER:\t${CMAKE_CXX_COMPILER}")
message("CLANG-TIDY:\t\t${clang_tidy}")
message("\n#####################################################\n")


add_executable(hello_world srcs/hello_world.cpp)

set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM.cmake")
set(CPM_DOWNLOAD_VERSION 0.27.1)

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION} AND CPM_VERSION STREQUAL CPM_DOWNLOAD_VERSION))
  message(STATUS "Downloading CPM.cmake")
  file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

CPMAddPackage(
  NAME Catch2
  GITHUB_REPOSITORY catchorg/Catch2
  VERSION 2.13.0
)

target_link_libraries(hello_world Catch2)

# tests
add_executable(tst tests/test.cpp)
target_link_libraries(tst Catch2)
#set_target_properties(CPMExampleCatch2 PROPERTIES CXX_STANDARD 17)
ENABLE_TESTING()
ADD_TEST(tst tst)

if (clang_tidy)
    set_target_properties(
            hello_world
            PROPERTIES CXX_CLANG_TIDY ${clang_tidy})
endif (clang_tidy)

