#include "JsonParser.h"
#include <simdjson.h>

std::vector<JsonParser::Row> JsonParser::parse(const std::string& jsonStr) {
    std::vector<Row> table;
    simdjson::ondemand::parser parser;
    auto doc = parser.iterate(jsonStr);

    for (auto obj : doc) {
        Row row;
        for (auto field : obj.get_object()) {
            row.cells.push_back(std::string(field.value()));
        }
        table.push_back(row);
    }
    return table;
}
