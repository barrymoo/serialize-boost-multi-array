cmake_minimum_required(VERSION 3.6)
project(vector)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(MPI REQUIRED)
find_package(Boost COMPONENTS serialization REQUIRED)

set(SOURCE_FILES test_mat.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})

target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}     
    ${Boost_INCLUDE_DIRS}
)

target_link_libraries(${CMAKE_PROJECT_NAME} ${Boost_LIBRARIES})
