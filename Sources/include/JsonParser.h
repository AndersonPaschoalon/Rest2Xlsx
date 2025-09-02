#pragma once
#include <string>
#include <vector>

class JsonParser {
public:
    struct Row {
        std::vector<std::string> cells;
    };
    std::vector<Row> parse(const std::string& jsonStr);
};
