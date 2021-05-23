cmake_minimum_required(VERSION 3.10)
set(PROJECT_NAME Plot)
project(${PROJECT_NAME} VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS OFF)
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})

file(GLOB_RECURSE SOURCE_FILES sources/*)
file(GLOB_RECURSE SOURCE_HEADERS include/*)
set(SOURCES ${SOURCE_FILES} ${SOURCE_HEADERS})

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include/)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})

find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)
