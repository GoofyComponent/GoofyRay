#Use this file to declare the newly created library

add_library(raymath
        ${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Vector3.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Ray.cpp
        Light.h
)
