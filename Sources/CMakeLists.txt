cmake_minimum_required(VERSION 3.15) # melhor usar >=3.15 porque FetchContent é mais estável

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Nome do projeto
project(HelloWorldProject LANGUAGES CXX)

# Definição de versão do C++ e debug
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)  # gera símbolos de debug (-g)

# Incluir diretórios de cabeçalhos
include_directories(include)

# Dependências externas
include(FetchContent)

# CPR
FetchContent_Declare(
  cpr
  GIT_REPOSITORY https://github.com/libcpr/cpr.git
  GIT_TAG 1.12.0
)
FetchContent_MakeAvailable(cpr)

# simdjson
FetchContent_Declare(
  simdjson
  GIT_REPOSITORY https://github.com/simdjson/simdjson.git
  GIT_TAG v3.13.0
)
FetchContent_MakeAvailable(simdjson)

# libxlsxwriter
FetchContent_Declare(
  xlsxwriter
  GIT_REPOSITORY https://github.com/jmcnamara/libxlsxwriter.git
  GIT_TAG v1.2.3
)
FetchContent_MakeAvailable(xlsxwriter)

## Executável
add_executable(
    rest2xlsx.exe
    ./src/DataPipeline.cpp
    ./src/JsonParser.cpp  
    ./src/RestClient.cpp  
    ./src/XlsxWriter.cpp  
    ./src/main.cpp
)

# Linkagem
target_link_libraries(rest2xlsx.exe 
    PRIVATE
    cpr::cpr
    simdjson::simdjson
    xlsxwriter
)
