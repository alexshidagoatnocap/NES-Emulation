add_library(nes_bus bus.cpp)

add_subdirectory(tests)

target_include_directories(nes_bus
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(nes_bus
  PUBLIC
    nes_aliases
)
