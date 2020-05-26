#include "gtest/gtest.h"

extern "C" {
#include "nextLevel.h"
}

TEST(upgrade, ok) {
	ASSERT_EQ(check(10), 1);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
