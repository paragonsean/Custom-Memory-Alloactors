# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.31
cmake_policy(SET CMP0009 NEW)

# SRC_FILES at CMakeLists.txt:6 (file)
file(GLOB NEW_GLOB LIST_DIRECTORIES true "/Users/spocam/Documents/GitHub/Custom-Memory-Alloactors/src/*.cpp")
set(OLD_GLOB
  "/Users/spocam/Documents/GitHub/Custom-Memory-Alloactors/src/FreeListAllocator.cpp"
  "/Users/spocam/Documents/GitHub/Custom-Memory-Alloactors/src/LinearAllocator.cpp"
  "/Users/spocam/Documents/GitHub/Custom-Memory-Alloactors/src/PoolAllocator.cpp"
  "/Users/spocam/Documents/GitHub/Custom-Memory-Alloactors/src/RBFreeListAllocator.cpp"
  "/Users/spocam/Documents/GitHub/Custom-Memory-Alloactors/src/StackAllocator.cpp"
  "/Users/spocam/Documents/GitHub/Custom-Memory-Alloactors/src/main.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/Users/spocam/Documents/GitHub/Custom-Memory-Alloactors/CMakeFiles/cmake.verify_globs")
endif()