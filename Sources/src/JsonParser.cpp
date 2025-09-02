#include "JsonParser.h"
#include <simdjson.h>

std::vector<JsonParser::Row> JsonParser::parse(const std::string& jsonStr) {
    /**
    std::vector<Row> table;
    simdjson::ondemand::parser parser;
    auto doc = parser.iterate(jsonStr);

    for (auto obj : doc) {
        Row row;
        for (auto field : obj.get_object()) {
            auto val = field.value();
            if (val.type() == simdjson::ondemand::json_type::string) {
                auto str = val.get_string().value();  // pega raw_json_string
                row.cells.push_back(std::string(str)); // converte para std::string
                printf(">> string: %.*s\n", (int)str.size(), str.data());
            } 
            else if (val.type() == simdjson::ondemand::json_type::boolean) {
                bool b = val.get_bool().value();
                row.cells.push_back(b ? "true" : "false");
                printf(">> bool: %s\n", b ? "true" : "false");
            }
            else if (val.type() == simdjson::ondemand::json_type::number) {
                double d = val.get_double().value();
                row.cells.push_back(std::to_string(d));
                printf(">> number: %f\n", d);
            }
            else {
                row.cells.push_back("<unsupported>");
            }
        }
        table.push_back(row);
    }
     
    return table;
    */
    std::vector<Row> table;
    simdjson::ondemand::parser parser;

    // Criar um padded_string para manter os dados vivos durante o parsing
    simdjson::padded_string padded_json(jsonStr);

    auto doc = parser.iterate(padded_json);


    Row row;
    for (auto field : doc.get_object()) {
        auto val = field.value();
        
        simdjson::ondemand::json_type t;
        if (auto err = val.type().get(t); err) {  // check type safely
            row.cells.push_back("<type_error>");
            continue;
        }

        switch (t) {
            case simdjson::ondemand::json_type::string: {
                auto str = val.get_string().value();
                row.cells.push_back(std::string(str));
                //printf(">> string: %.*s\n", (int)str.size(), str.data());
                break;
            }
            case simdjson::ondemand::json_type::boolean: {
                bool b = val.get_bool().value();
                row.cells.push_back(b ? "true" : "false");
                //printf(">> bool: %s\n", b ? "true" : "false");
                break;
            }
            case simdjson::ondemand::json_type::number: {
                double d = val.get_double().value();
                row.cells.push_back(std::to_string(d));
                //printf(">> number: %f\n", d);
                break;
            }
            default:
                row.cells.push_back("<unsupported>");
        }
    }

    table.push_back(std::move(row));

    return table;
}
