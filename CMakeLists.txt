cmake_minimum_required(VERSION 3.12)

# Pull in PICO SDK (must be before project)
set(PICO_SDK_FETCH_FROM_GIT on)
include(pico_sdk_import.cmake)

include_directories($ENV{CARP_DIR}/core)

project(pico_keypad_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)


# Initialize the SDK
pico_sdk_init()

add_subdirectory(pimoroni-pico/drivers)
add_subdirectory(pimoroni-pico/libraries)

file(GLOB_RECURSE CARP_FILES ${PROJECT_SOURCE_DIR}/*.carp)

add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/carp-out/main.c
    COMMAND carp -b --no-core ${CMAKE_CURRENT_SOURCE_DIR}/main.carp
    DEPENDS ${CARP_FILES}
)

add_executable(
  pico_keypad
  lib/keypad.cpp
  ${CMAKE_CURRENT_BINARY_DIR}/carp-out/main.c
)

# Pull in pico libraries that we need
target_link_libraries(pico_keypad pico_stdlib pico_rgb_keypad)

# create map/bin/hex file etc.
pico_add_extra_outputs(pico_keypad)

