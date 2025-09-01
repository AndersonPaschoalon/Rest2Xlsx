#include "HelloWorld.h"
#include <iostream>

HelloWorld::HelloWorld() {
    // Construtor
}

void HelloWorld::hello() const {
    std::cout << "Hello World!" << std::endl;
}

// Dummy cpr test
void HelloWorld::helloCPR() const {
    // apenas cria um objeto Response vazio
    cpr::Response r;
    std::cout << "Hello CPR! Status code dummy: " << r.status_code << std::endl;
}

// Dummy simdjson test
void HelloWorld::helloSimdJSON() const {
    simdjson::dom::parser parser;

    // JSON simples
    const char* json_literal = "{}" ;
    simdjson::padded_string json_data(json_literal, strlen(json_literal));

    simdjson::dom::element doc;
    auto result = parser.parse(json_data);  // parse com padded_string

    if (result.error()) {
        std::cerr << "Simdjson parse failed: " << result.error() << "\n";
        return;
    }

    doc = result.value();  // acessar elemento

    std::cout << "Hello Simdjson! type: " << int(doc.type()) << "\n";
}

// Dummy xlsxwriter test
void HelloWorld::helloXLSX() const {
    lxw_workbook* workbook = workbook_new("/tmp/dummy.xlsx"); // cria e descarta
    if(workbook) {
        std::cout << "Hello xlsxwriter! Workbook pointer: " << workbook << std::endl;
        workbook_close(workbook);
    }
}