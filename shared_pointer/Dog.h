#pragma once

#include <iostream>

struct Dog {
public:

    Dog() = default;
    Dog(const std::string & breed, double height, double weidth): breed(breed), height(height), weight(weidth) {

    }

    ~Dog() = default;

    std::string breed{"n/a"};
    double height{0.0};
    double weight{0.0};
};