cmake_minimum_required(VERSION 3.5.0)
project(goofyray VERSION 0.1.0 LANGUAGES C CXX)

set (CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(goofyray main.cpp)

# Since our project is name goofyray, we need to use the target name goofyray instead of raytracer (the example project name)
target_include_directories(goofyray PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_SOURCE_DIR}/src/raymath"
                            "${PROJECT_SOURCE_DIR}/src/rayimage"
                            "${PROJECT_SOURCE_DIR}/src/lodepng"
                            "${PROJECT_SOURCE_DIR}/src/userinputs"
                            "${PROJECT_SOURCE_DIR}/src/core"
                            "${PROJECT_SOURCE_DIR}/src/object"
                           )

add_subdirectory(./src/raymath)
add_subdirectory(./src/rayimage)
add_subdirectory(./src/lodepng)
add_subdirectory(./src/userinputs)
add_subdirectory(./src/core)
add_subdirectory(./src/object)

target_link_libraries(goofyray PUBLIC raymath)
target_link_libraries(goofyray PUBLIC rayimage)
target_link_libraries(goofyray PUBLIC lodepng)
target_link_libraries(goofyray PUBLIC userinputs)
target_link_libraries(goofyray PUBLIC core)
target_link_libraries(goofyray PUBLIC object)
