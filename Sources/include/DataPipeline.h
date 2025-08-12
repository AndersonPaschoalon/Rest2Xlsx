#pragma once
#include <string>
#include "RestClient.h"
#include "JsonParser.h"
#include "XlsxWriter.h"

class DataPipeline {
    RestClient restClient;
    JsonParser jsonParser;
    XlsxWriter xlsxWriter;

public:
    void run(const std::string& endpoint, const std::string& outputFile);
};
