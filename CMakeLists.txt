cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pico_bmp180 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(pico_bmp180
    main.c
    bmp180.c
)

pico_enable_stdio_usb(pico_bmp180 1)
pico_enable_stdio_uart(pico_bmp180 1)

pico_add_extra_outputs(pico_bmp180)

target_include_directories(pico_bmp180 PRIVATE ${CMAKE_CURRENT_LIST_DIR} )


target_link_libraries(pico_bmp180 
    pico_stdlib
    hardware_i2c
    )
