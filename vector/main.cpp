#include <cassert>
#include <iostream>

#include "Vector.h"

template<typename T>
void printVal(const std::string & txt, const Vector<T>& vecIn) {
    std::cout << txt << '\n';
    for (size_t i = 0; i < vecIn.size(); ++i) {
        std::cout << '\t' << vecIn.at(i) << '\n';
    }
}

int main() {

    const size_t num{10};
    const int val{5};

    Vector<int> vec1(num, val);
    printVal<int>("vector 1 - initialized with same value", vec1);

    for (size_t i = 0; i < num; ++i) {
        vec1[i] *= 2;
    }
    printVal<int>("vector 1 has been doubled", vec1);

    Vector<double> vec2;
    for (size_t i = 0; i < num; ++i) {
        vec2.push_back(static_cast<double>(i));
    }
    printVal("vector 2 - values are pushed back", vec2);

    Vector<double> vec3(vec2);
    printVal("vector 3 - copy-constructed by vec2", vec3);

    Vector<double>::iterator beginVec2{vec2.begin()};
    Vector<double>::iterator endVec2{vec2.end()};
    std::cout << "vec2.begin() = " << beginVec2 << '\n';
    std::cout << "vec2.end() = " << endVec2 << '\n';

    Vector<double>::iterator beginVec3{vec3.begin()};
    Vector<double>::iterator endVec3{vec3.end()};
    std::cout << "vec3.begin() = " << beginVec3 << '\n';
    std::cout << "vec3.end() = " << endVec3 << '\n';

    Vector<double> vec4;
    vec4 = vec3;
    std::cout << "vec4.begin() = " << vec4.begin() << '\n';
    std::cout << "vec4.end() = " << vec4.end() << '\n';

    return EXIT_SUCCESS;
}