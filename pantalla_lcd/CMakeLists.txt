cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(pantalla_lcd C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(pantalla_lcd pantalla_lcd.c ssd1306.c ssd1306.h font.h)

pico_enable_stdio_usb(pantalla_lcd 0)
pico_enable_stdio_uart(pantalla_lcd 0)
pico_add_extra_outputs(pantalla_lcd)

target_link_libraries(pantalla_lcd pico_stdlib hardware_i2c)
