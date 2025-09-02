#pragma once
#include <string>

class RestClient {
public:
    std::string fetchData(const std::string& url);
};
