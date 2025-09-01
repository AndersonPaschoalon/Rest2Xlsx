#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include <string>
#include <cpr/cpr.h>
// #include <cpr/cpr.h>
#include <simdjson.h>
#include <xlsxwriter.h>


class HelloWorld {
public:
    HelloWorld();

    void hello() const;

    void helloCPR() const;
    void helloSimdJSON() const;
    void helloXLSX() const;
};

#endif
