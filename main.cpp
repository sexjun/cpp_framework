#include "toolHead.h"
#include <iostream>

static void logInit() {
    spdlog::cfg::load_env_levels();
    spdlog::set_level(static_cast<level::level_enum>(SPDLOG_LEVEL_INFO));
    spdlog::error("malloc failed");
    return;
}

int main(int, char**) {
    std::cout << "Hello, world!\n";
    toolHeadTest();
    logInit();
}
