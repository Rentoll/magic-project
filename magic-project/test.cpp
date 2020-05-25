#include "gtest/gtest.h"

extern "C" {
#include "nextLevel.h"
}

TEST(upgrade, ok) {
	ASSERT_EQ(check(10), 1);
}
