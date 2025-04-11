#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    if (b > 0 && (a > std::numeric_limits<int>::max() - b)) {
        throw std::overflow_error("Add Overflow");
    }
    if (b < 0 && (a < std::numeric_limits<int>::min() - b)) {
        throw std::overflow_error("Add Underflow");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    if (b < 0 && (a > std::numeric_limits<int>::max() + b)) {
        throw std::overflow_error("Subtraction Overflow");
    }
    if (b > 0 && (a < std::numeric_limits<int>::min() + b)) {
        throw std::overflow_error("Subtraction Underflow");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    if (a > 0) {
        if (b > 0 && a > std::numeric_limits<int>::max() / b) {
            throw std::overflow_error("Multiply Overflow");
        }
        if (b < 0 && b < std::numeric_limits<int>::min() / a) {
            throw std::overflow_error("Multiply Underflow");
        }
    } 
    else if (a < 0) {
        if (b > 0 && a < std::numeric_limits<int>::min() / b) {
            throw std::overflow_error("Multiply Underflow");
        }
        if (b < 0 && a < std::numeric_limits<int>::max() / b) {
            throw std::overflow_error("Multiply Overflow");
        }
    }
    return a * b;
}

int Calculator::div(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if (a == std::numeric_limits<int>::min() && b == -1) {
        throw std::overflow_error("Division Overflow"); 
    }
    return a / b;
}
