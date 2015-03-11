#include "myClass.hpp"

void MyClass::incrementX(){
    ++x;
    ++x;
}

void MyClass::incrementY(){
    ++x;
}

int MyClass::getX() const { return x; }

void MyClass::setX(int x_) { x = x_; }

std::string MyClass::getStringFromInstance(const MyClass& instance) {
    return instance.y;
}