#include "RestClient.h"
#include <cpr/cpr.h>
#include <stdexcept>

std::string RestClient::fetchData(const std::string& url) {
    auto response = cpr::Get(cpr::Url{url});
    if (response.status_code != 200) {
        throw std::runtime_error("Failed to fetch data: HTTP " + std::to_string(response.status_code));
    }
    return response.text;
}
