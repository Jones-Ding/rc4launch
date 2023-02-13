cmake_minimum_required(VERSION 3.8)
project(rc4launch)

set(CMAKE_BUILD_TYPE "Release")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)
aux_source_directory(${PROJECT_SOURCE_DIR}/src/ SRC_LIST)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_C_VISIBILITY_PRESET hidden)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

add_executable(rc4launch ${SRC_LIST})
target_link_libraries(rc4launch rc4encrypt.a)
