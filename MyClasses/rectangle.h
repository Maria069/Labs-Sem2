#pragma once
#include <iostream>

class Rectangle {
    double a = 0;
    double b = 0;
public:
    Rectangle() {}
    Rectangle(double a1, double b1) {
        a = a1;
        b = b1;
    }
    Rectangle(const Rectangle &other) {
        a = other.a;
        b = other.b;
    }
    ~Rectangle() {}

    friend std::ostream &operator<<(std::ostream &out, Rectangle &obj) {
        out << obj.a << ' ' << obj.b << '\n';
        return out;
    }

    bool operator<(const Rectangle &obj) const {
        return (a * b) < (obj.a * obj.b);
    }

    bool operator==(const Rectangle &obj) {
        return (a == obj.a) && (b == obj.b);
    }

};
