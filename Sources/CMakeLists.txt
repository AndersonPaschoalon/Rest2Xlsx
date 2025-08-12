cmake_minimum_required(VERSION 3.15)
project(MyExporterApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add dependencies
add_subdirectory(libs/cpr)
add_subdirectory(libs/simdjson)
add_subdirectory(libs/libxlsxwriter)

# Include paths
include_directories(include)
include_directories(libs/cpr/include)
include_directories(libs/simdjson/include)
include_directories(libs/libxlsxwriter/include)

# Sources
file(GLOB SOURCES src/*.cpp main.cpp)

# Build executable
add_executable(MyExporter ${SOURCES})

# Link dependencies
target_link_libraries(MyExporter PRIVATE cpr::cpr simdjson xlsxwriter)
