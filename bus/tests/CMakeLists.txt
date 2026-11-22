enable_testing()

add_executable(bus_tests
  ../bus.cpp
  # load_store_op_tests.cpp
)

target_link_libraries(bus_tests
  PRIVATE
    nes_aliases
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(bus_tests)
