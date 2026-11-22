#include "../cpu.hpp"
#include <gtest/gtest.h>

class LoadStoreOpTests : public ::testing::Test {
public:
  NES::CPU testCpu{};

  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(LoadStoreOpTests, ldaTest) {
  testCpu.lda(0xDE);
  // EXPECT_EQ(testCpu.sta(), 0xDE);
}
