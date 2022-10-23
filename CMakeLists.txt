cmake_minimum_required(VERSION 3.12)

set(NAME pico-keypad)

include(pimoroni_pico_import.cmake)
include(pico_sdk_import.cmake)

project(${NAME} C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

include_directories(
  ${CMAKE_CURRENT_LIST_DIR}
  $ENV{CARP_DIR}/core
  lib
)

add_subdirectory(pimoroni-pico/common)
add_subdirectory(pimoroni-pico/drivers)
add_subdirectory(pimoroni-pico/libraries)

file(GLOB_RECURSE CARP_FILES ${PROJECT_SOURCE_DIR}/*.carp)

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/carp-out/main.c
  COMMAND carp -b --no-core ${CMAKE_CURRENT_SOURCE_DIR}/main.carp
  DEPENDS ${CARP_FILES}
)

# Source files
add_executable(${NAME}
  lib/usb_descriptors.c
  lib/keypad.cpp
  lib/usb.c
  ${CMAKE_CURRENT_BINARY_DIR}/carp-out/main.c
)

# Libraries
target_link_libraries(${NAME}
  pico_stdlib
  pico_rgb_keypad
  tinyusb_device
  tinyusb_board
)

pico_add_extra_outputs(${NAME})

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/${NAME}.uf2
    ${CMAKE_CURRENT_LIST_DIR}/README.md
    DESTINATION .
)

set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
set(CPACK_GENERATOR "ZIP" "TGZ")
include(CPack)
