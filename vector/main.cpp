#include <iostream>

#include "Vector.h"

template<typename T>
void printVal(const Vector<T>& vecIn) {
    for (size_t i = 0; i < 2 * vecIn.size(); ++i) {
        std::cout << vecIn.at(i) << '\n';
    }
}

int main() {

    const size_t num{10};
    const int val{5};

    Vector<int> myVec(num, val);
    printVal<int>(myVec);

    for (size_t i = 0; i < num; ++i) {
        myVec[i] *= 2;
    }
    printVal<int>(myVec);

    return EXIT_SUCCESS;
}