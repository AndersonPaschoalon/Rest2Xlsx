#include "DataPipeline.h"
#include <iostream>

void DataPipeline::run(const std::string& endpoint, const std::string& outputFile) {
    std::cout << "[*] Fetching data from " << endpoint << std::endl;
    std::string jsonData = restClient.fetchData(endpoint);

    std::cout << "[*] Parsing JSON..." << std::endl;
    auto parsedData = jsonParser.parse(jsonData);

    std::cout << "[*] Writing XLSX file: " << outputFile << std::endl;
    xlsxWriter.write(outputFile, parsedData);

    std::cout << "[+] Done!" << std::endl;
}


