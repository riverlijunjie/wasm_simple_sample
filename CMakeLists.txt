cmake_minimum_required (VERSION 3.10)
project("wasm_test")
set(TARGET_NAME "wasm_test")

set(CMAKE_C_COMPILER emcc)
set(CMAKE_CXX_COMPILER em++)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -sPROXY_TO_PTHREAD=1 -sEXIT_RUNTIME=1 -fexceptions -Wno-unused-command-line-argument")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -s MODULARIZE -s EXPORT_NAME=\"createModule\"")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pthread -s -g2 -O0  -s EXPORTED_RUNTIME_METHODS=\"['ccall', 'FS']\" --bind")

add_executable(${TARGET_NAME} thread_test.cpp)

