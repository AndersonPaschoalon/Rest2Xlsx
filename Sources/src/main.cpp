#include "DataPipeline.h"
#include <iostream>

int main() {
    try {
        DataPipeline pipeline;
        // /consolidado/completo/ultima_versao
        // pipeline.run("http://192.168.0.35:8082/get_version", "get_version.xlsx");
        pipeline.run("http://192.168.0.35:8082/consolidado/completo/ultima_versao", "get_version.xlsx");
    } catch (const std::exception& ex) {
        std::cerr << "[ERROR] " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
