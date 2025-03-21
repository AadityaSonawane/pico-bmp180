cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pico_bmp180 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_library(pico_bmp180 STATIC bmp180.c)

target_include_directories(pico_bmp180 PUBLIC ${CMAKE_CURRENT_LIST_DIR} )

target_link_libraries(pico_bmp180 
    pico_stdlib
    hardware_i2c
    )
