cmake_minimum_required(VERSION 3.0.0)
project(cpp_framework VERSION 0.1.0)

include(CTest)
enable_testing()

include(GoogleTest)

# spdlog的部分配置
add_subdirectory(lib/spdlog)
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()

# googletest部分的配置
add_subdirectory(lib/googtest)

# 最终主项目的设置
include_directories(./include)
aux_source_directory(./src SRC_DIR)
add_executable(cpp_framework main.cpp ${SRC_DIR})

target_link_libraries(cpp_framework 
PRIVATE
spdlog::spdlog
gtest_main
)
message(STATUS "SRC_DIR: ${SRC_DIR}")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
