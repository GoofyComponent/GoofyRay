#Use this file to declare the newly created library

add_library(core
  ${CMAKE_CURRENT_SOURCE_DIR}/Camera.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Scene.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Input.cpp
        ObjLoader.cpp
        ObjLoader.h
)
