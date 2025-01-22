cmake_minimum_required(VERSION 3.15)

project(test_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-DGTEST_LANGUAGE_CXX11)

set(PRJ_DIR ..)

set(PRJ_SRC_DIR ${PRJ_DIR}/source)
set(PRJ_INC_DIR ${PRJ_DIR}/include)

enable_testing()

find_package(Threads REQUIRED)

find_package(GTest REQUIRED)
include_directories(${INCLUDE_DIRECTORIES}, /usr/include)
include_directories(${INCLUDE_DIRECTORIES}, ${PRJ_INC_DIR})

add_executable(test_1 main.cpp tst_test_1.cpp ${PRJ_SRC_DIR}/my_lib.cpp)
add_test(NAME test_1 COMMAND test_1)
target_link_libraries(test_1 PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} Threads::Threads )
