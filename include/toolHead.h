#include<iostream>
#include <fstream>
#include <string>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/cfg/env.h"

#ifdef _WIN32
#include <direct.h>
#elif __APPLE__ || __linux__
#include<unistd.h>
#endif

using namespace std;
using namespace spdlog;

static string getWorkPath(){
    char runPath[1024] = {0};
    getcwd(runPath, sizeof(runPath));
    return string(runPath);
}

static void getOprationSystemType(){
    #ifdef _WIN32
    cout << "This is Windows" << endl;
    #elif __APPLE__ || __linux__
    cout << "This is Linux" << endl;
    #endif
}

// void testlog(){
//     // load_levels_example();
//     spdlog::cfg::load_env_levels();
//     spdlog::set_level(static_cast<level::level_enum>(SPDLOG_LEVEL_ERROR));
// }

// static void initLogSystem();

void toolHeadTest();