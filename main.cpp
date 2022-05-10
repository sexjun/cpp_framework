#include "toolHead.h"
#include <iostream>
#include <thread>

static void logInit() {
    spdlog::cfg::load_env_levels();
    spdlog::set_level(static_cast<level::level_enum>(SPDLOG_LEVEL_INFO));
    spdlog::error("malloc failed");
    return;
}

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

int main(int argc, char** argv) {
    thread t1(logInit);
    t1.join();
    std::cout << "Hello, world!\n";
    toolHeadTest();
    logInit();
    spdlog::set_level(spdlog::level::info); // Set global log level to info
    spdlog::debug("This message should not be displayed!");
    spdlog::set_level(spdlog::level::trace); // Set specific logger's log level
    spdlog::debug("This message should be displayed..");::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
