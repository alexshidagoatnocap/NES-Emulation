add_library(nes_cpu cpu.cpp)

add_subdirectory(tests)

target_include_directories(nes_cpu
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(nes_cpu
  PUBLIC
    nes_aliases
)
