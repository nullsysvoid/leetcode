cmake_minimum_required(VERSION 3.0.0)
set(TARGET_NAME sample)
project(${TARGET_NAME} VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(sample main.cpp)

target_link_libraries(${TARGET_NAME}
  GTest::gtest_main
  ${CMAKE_SOURCE_DIR}/../../utils/utils.cpp
)

target_include_directories(${TARGET_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/../../utils/
)
