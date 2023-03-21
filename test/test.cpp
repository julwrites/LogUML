#include "../loguml.hpp"
#include <gtest/gtest.h>

TEST(TestGTest, BasicAsserts) {
  EXPECT_STRNE("This", "That");

  EXPECT_EQ(10, 5 * 2);
}
