#pragma once
#include <string>
#include <vector>
#include "JsonParser.h"

class XlsxWriter {
public:
    void write(const std::string& filename, const std::vector<JsonParser::Row>& data);
};
