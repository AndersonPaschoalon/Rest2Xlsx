#include "DataPipeline.h"

int main() {
    try {
        DataPipeline pipeline;
        pipeline.run("http://localhost:8000/data_endpoint", "output.xlsx");
    } catch (const std::exception& ex) {
        std::cerr << "[ERROR] " << ex.what() << std::endl;
        return 1;
    }
    return 0;
}
