#include <iostream>
#include <cmath>
#include "calculator.h"

using namespace std;

float Calculator::add(float x, float y) {
    return x + y;
}

float Calculator::subtract(float x, float y) {
    return x - y;
}

float Calculator::multiply(float x, float y) {
    return x * y;
}

float Calculator::divide(float x, float y) {
    if (y) return x / y;
    return NULL;
}

float Calculator::exponent(float x, float y) {
    return pow(x, y);
}

float Calculator::root(float x, float y) {
    if (y) return pow(x, 1/y);
    return NULL;
}

float Calculator::root(float x, float y) {
    return 0;
}

int Calculator::factorial(int x) {
    for (int i = x; i > 2; i--) {
        x *= i - 1;
    }
    return x;
}