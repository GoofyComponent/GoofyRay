#Use this file to declare the newly created library

add_library(raymath 
  ${CMAKE_CURRENT_SOURCE_DIR}/Color.cpp
        Ray.h
        Vector3.cpp
        Hittable.h
)
