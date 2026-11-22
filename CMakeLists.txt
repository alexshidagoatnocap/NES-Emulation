cmake_minimum_required(VERSION 3.28)

project(nes_emulator LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_subdirectory(aliases)
add_subdirectory(bus)
add_subdirectory(cpu)

add_executable(nes-emu main.cpp)
target_link_libraries(nes-emu
  PRIVATE
    nes_cpu
)
