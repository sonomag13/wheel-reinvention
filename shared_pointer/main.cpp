#include <cassert>
#include <iostream>

#include "Dog.h"
#include "SharedPointer.h"

int main() {

    // this is the target
    auto dogGermanShepherd = new Dog("german-shepherd", 0.60, 35);

    SharedPointer<Dog> sharedPtr1;
    assert(sharedPtr1.getCounter() == 0);

    // test copy assignment
    SharedPointer<Dog> sharedPtr2(dogGermanShepherd);
    sharedPtr1 = sharedPtr2;
    assert(sharedPtr1.getPointer() == sharedPtr2.getPointer());  // point to the same thing
    assert(sharedPtr1.getCounter() == sharedPtr2.getCounter());  // point to the same thing
    assert(sharedPtr1.getCounter() == 2);  // point to the same thing

    // test copy construction
    SharedPointer<Dog> sharedPtr3(sharedPtr2);
    assert(sharedPtr1.getPointer() == sharedPtr2.getPointer());  // point to the same thing
    assert(sharedPtr1.getPointer() == sharedPtr3.getPointer());  // point to the same thing
    assert(sharedPtr1.getCounter() == sharedPtr2.getCounter());  // point to the same thing
    assert(sharedPtr1.getCounter() == sharedPtr3.getCounter());  // point to the same thing
    assert(sharedPtr1.getCounter() == 3);  // point to the same thing

    // test move construction
    SharedPointer<Dog> sharedPtr4(std::move(sharedPtr3));
    assert(sharedPtr1.getPointer() == sharedPtr4.getPointer());  // point to the same thing
    assert(sharedPtr1.getCounter() == sharedPtr4.getCounter());  // point to the same thing
    assert(sharedPtr1.getCounter() == 3);  // point to the same thing

    // test move assignment
    SharedPointer<Dog> sharedPtr5(new Dog("chihuahua", 0.10, 4));
    SharedPointer<Dog> sharedPtr6(sharedPtr5);
    sharedPtr4 = std::move(sharedPtr5);
    assert(sharedPtr4.getPointer() == sharedPtr6.getPointer());  // point to the same thing
    assert(sharedPtr4.getCounter() == sharedPtr6.getCounter());  // point to the same thing
    assert(sharedPtr4.getCounter() == 2);  // point to the same thing

    return 0; 
}