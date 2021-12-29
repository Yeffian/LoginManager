cmake_minimum_required(VERSION 3.13)  
project(login_manager)           
set(CMAKE_CXX_STANDARD 17)   

set(SOURCE_FILES src/main.cpp)

add_executable(login_manager ${SOURCE_FILES})