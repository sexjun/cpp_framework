#include "toolHead.h"
#include <gtest/gtest.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include "tinyxml2.h"
using namespace tinyxml2;

#include <iostream>
#include <thread>
#include <vector>
#include <string>

static void logInit() {
    spdlog::cfg::load_env_levels();
    spdlog::set_level(static_cast<level::level_enum>(SPDLOG_LEVEL_INFO));
    spdlog::error("malloc failed");
    return;
}


// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}

void initGoogleTest()
{
    // ::testing::InitGoogleTest(1, 0);
    // RUN_ALL_TESTS();
}

void initLogSystem()
{
    logInit();
    spdlog::set_level(spdlog::level::info); // Set global log level to info
    spdlog::debug("This message should not be displayed!");
    spdlog::set_level(spdlog::level::trace); // Set specific logger's log level
    spdlog::debug("This message should be displayed..");
}

int json_test(vector<int> &hash_list, vector<string> &string_list)
{
    // read a JSON file
    std::ifstream i("../res/test.json");
    json file_json_obj;
    if(i.is_open()) {
        i >> file_json_obj;
    } else {
        error("file not fonud");
    }
    for(int i = 0; i < file_json_obj.size(); i++) {
        hash_list.push_back(file_json_obj.at(0)["hash_value"]);
        string_list.push_back(file_json_obj.at(0)["string_value"]);
    }
    debug("json map size : {}", file_json_obj.size());

    std::ofstream o("../res/test_3.json");
    o << std::setw(4) << file_json_obj << std::endl;
    o << "end";
    o.close();
    return 1;
}

int initXml()
{
    	static const char* xml =
		"<?xml version=\"1.0\"?>"
		"<!DOCTYPE PLAY SYSTEM \"play.dtd\">"
		"<PLAY>"
		"<TITLE>A Midsummer Night's Dream</TITLE>"
		"</PLAY>";

	XMLDocument doc;
	doc.Parse( xml );

	XMLElement* titleElement = doc.FirstChildElement( "PLAY" )->FirstChildElement( "TITLE" );
	const char* title = titleElement->GetText();
	// printf( "Name of play (1): %s\n", title );

	XMLText* textNode = titleElement->FirstChild()->ToText();
	title = textNode->Value();
	// printf( "Name of play (2): %s\n", title );

	return doc.ErrorID();
    return 1;
}

int main(int argc, char** argv) {

    toolHeadTest();
    vector<int> hash_list;
    vector<string> string_list;
    json_test(hash_list, string_list);
    initXml();
    return 1;
}
