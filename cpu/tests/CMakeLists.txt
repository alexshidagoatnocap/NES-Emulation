enable_testing()

add_executable(cpu_tests
  ../cpu.cpp
  load_store_op_tests.cpp
)

target_link_libraries(cpu_tests
  PRIVATE
    nes_aliases
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(cpu_tests)
