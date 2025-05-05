#pragma once
#include <iostream>

class Complex {
    double x = 0;
    double i = 0;
public:
    Complex() {}
    Complex(double x1, double i1) {
        x = x1;
        i = i1;
    }
    Complex(const Complex &other) {
        x = other.x;
        i = other.i;
    }
    ~Complex() {}

    friend std::ostream &operator<<(std::ostream &out, Complex &obj) {
        if (obj.i >= 0) {
            out << obj.x << " + i * " << obj.i << '\n';
        } else {
            out << obj.x << " - i * " << obj.i * (-1) << '\n';
        }
        return out;
    }

    Complex operator+(const Complex& obj) {
        return Complex(x + obj.x, i + obj.i);
    }
    Complex operator+=(const Complex& obj) {
        x += obj.x;
        i += obj.i;
        return *this;
    }

};
