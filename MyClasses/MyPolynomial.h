#pragma once
#include "MyVector.h"
#include <iostream>
#include <iostream>

namespace {
  const int kSize = 500;
} // namespace


class MyTerm {
public:
    int koef = 0;
    int pow = 0;
    MyTerm(int koef1 = 0, int pow1 = 0) : koef(koef1), pow(pow1) {}
    MyTerm(const MyTerm& obj) {
        koef = obj.koef;
        pow = obj.pow;
    }

    MyTerm(const char* inputString) {
        int i = 0;
        bool flag = false;
        bool flagKoef = false;
        koef = 0;
        while(i < strlen(inputString) && inputString[i] != 'x') {
            if (inputString[i] == '-') {
                flag = true;
            } else if ((inputString[i] - '0') >= 0 && (inputString[i] - '0') <= 9) {
                flagKoef = true;
                koef *= 10;
                koef += (inputString[i] - '0');
            }
            ++i;
        }
        if (!flagKoef && koef == 0) {
            koef = 1;
        }
        if (flag) {
            koef *= (-1);
        }
        if (i >= strlen(inputString) && inputString[i] != 'x') {
            pow = 0;
            return;
        }
        flag = false;
        bool flagPow = false;
        pow = 0;
        while(i < strlen(inputString)) {
            if (inputString[i] == '-') {
                flag = true;
            } else if ((inputString[i] - '0') >= 0 && (inputString[i] - '0') <= 9) {
                flagPow = true;
                pow *= 10;
                pow += (inputString[i] - '0');
            }
            ++i;
        }
        if (flag) {
            pow *= (-1);
        }
        if (pow == 0 && !flagPow) {
            pow = 1;
        }
    }
    MyTerm& operator=(const MyTerm& obj) {
        if (this == &obj) {
            return *this;
        }
        koef = obj.koef;
        pow = obj.pow;
        return *this;
    }
    ~MyTerm() {}

    bool operator<(const MyTerm& obj) {
        return pow < obj.pow;
    }
    bool operator>(const MyTerm& obj) {
        return pow > obj.pow;
    }

    MyTerm operator+(const MyTerm& obj) {
        if (pow != obj.pow) {
            std::cout << "Нельзя сложить разные степени\n";
            return MyTerm();
        }
        if (koef + obj.koef == 0) {
            return MyTerm();
        }
        return MyTerm(koef + obj.koef, pow);
    }
    MyTerm operator+=(const MyTerm& obj) {
        if (pow != obj.pow) {
            std::cout << "Нельзя сложить разные степени\n";
            return MyTerm();
        }
        if (koef + obj.koef == 0) {
            koef = 0;
            pow = 0;
            return *this;
        }
        
        koef += obj.koef;
        
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, MyTerm &obj) {
        if (abs(obj.koef) != 1) {
            out << obj.koef;
        } else if (obj.koef == -1) {
            out << '-';
        }
        if (obj.pow == 0 || obj.koef == 0) {
            out << '\n';
            return out;
        }
        if (obj.pow == 1) {
            out << 'x' << '\n';
            return out;
        }
        out << "x^" << obj.pow << '\n';
        return out;
    }
    friend std::istream &operator>>(std::istream &in, MyTerm &obj) {
        char inputString[kSize];
        in.getline(inputString, kSize);
        obj = MyTerm(inputString);
        return in;
    }
};

class MyPolynomial {
    MyVector<MyTerm> poly;
    int degree;
    bool order = true;
public:
    MyPolynomial(int koef1 = 0, int pow1 = 0) {
        poly.add_element(MyTerm(koef1, pow1));
        degree = pow1;
    }
    MyPolynomial(MyTerm obj) {
        poly.add_element(obj);
        degree = obj.pow;
    }
    MyPolynomial(const MyPolynomial& obj) {
        poly = obj.poly;
        degree = obj.degree;
        order = obj.order;
    }
    ~MyPolynomial() {}

    MyPolynomial& operator=(const MyPolynomial& obj) {
        if (this == &obj) {
            return *this;
        }
        poly = obj.poly;
        degree = obj.degree;
        order = obj.order;
        return *this;
    }
    //+ * += *= term
    MyPolynomial operator+(const MyTerm& obj) {
        MyPolynomial tmp;
        tmp.degree = degree;

        bool flag = false;
        for (int i = 0; i < poly.getSize(); ++i) {
            if (obj.pow == poly[i].pow) {
                tmp.poly.add_element(MyTerm(obj.koef + poly[i].koef, poly[i].pow));
                flag = true; 
            } else {
                tmp.poly.add_element(MyTerm(poly[i].koef, poly[i].pow));
            }
        }
        if (!flag) {
            tmp.poly.add_element(obj);
            if (obj.pow > degree) {
                tmp.degree = obj.pow;
            }
        }
        tmp.poly.sort(order);
        return tmp;
    }
    MyPolynomial& operator+=(const MyTerm& obj) {
        MyPolynomial tmp;
        tmp.degree = degree;

        bool flag = false;
        for (int i = 0; i < poly.getSize(); ++i) {
            if (obj.pow == poly[i].pow) {
                tmp.poly.add_element(MyTerm(obj.koef + poly[i].koef, poly[i].pow));
                flag = true; 
            } else {
                tmp.poly.add_element(MyTerm(poly[i].koef, poly[i].pow));
            }
        }
        if (!flag) {
            tmp.poly.add_element(obj);
            if (obj.pow > degree) {
                tmp.degree = obj.pow;
            }
        }

        *this = tmp;
        poly.sort(order);
        return *this;
    }

    MyPolynomial operator*(const MyTerm& obj) {
        MyPolynomial tmp;
        
        for (int i = 0; i < poly.getSize(); ++i) {
            tmp.poly.add_element(MyTerm(poly[i].koef * obj.koef, poly[i].pow + obj.pow));
        }
        tmp.degree = degree + obj.pow;
        return tmp;
    }
    MyPolynomial& operator*=(const MyTerm& obj) {
        MyPolynomial tmp;
        
        for (int i = 0; i < poly.getSize(); ++i) {
            tmp.poly.add_element(MyTerm(poly[i].koef * obj.koef, poly[i].pow + obj.pow));
        }
        tmp.degree = degree + obj.pow;

        *this = tmp;
        return *this;
    }

    //+ *
    MyPolynomial operator+(const MyPolynomial& obj) {
        MyPolynomial tmp(*this);

        for (int j = 0; j < obj.poly.getSize(); ++j) {
            tmp += obj.poly[j];
        }

        tmp.poly.sort(order);
        return tmp;
    }
    MyPolynomial operator*(const MyPolynomial& obj) {
        MyPolynomial tmp1;

        for (int j = 0; j < obj.poly.getSize(); ++j) {
            MyPolynomial tmp(*this);
            tmp *= obj.poly[j];
            tmp1 += tmp;
        }

        tmp1.poly.sort(order);
        return tmp1;
    }

    //+= *=
    MyPolynomial& operator+=(const MyPolynomial& obj) {
        for (int j = 0; j < obj.poly.getSize(); ++j) {
            *this += obj.poly[j];
        }

        poly.sort(order);
        return *this;
    }
    MyPolynomial& operator*=(const MyPolynomial& obj) {
        
        MyPolynomial tmp1;

        for (int j = 0; j < obj.poly.getSize(); ++j) {
            MyPolynomial tmp(*this);
            tmp *= obj.poly[j];
            tmp1 += tmp;
        }

        tmp1.poly.sort(order);

        *this = tmp1;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &out, const MyPolynomial &obj) {
        if ((obj.order && obj.poly[0].koef == 0)||(!obj.order && obj.poly[obj.poly.getSize() - 1].koef == 0)) {
            out << 0 << '\n';
            return out;
        }
        if (obj.poly[0].koef != 0) {
            if (abs(obj.poly[0].koef) != 1) {
                out << obj.poly[0].koef;
            } else if (obj.poly[0].koef == -1) {
                out << '-';
            }
            if (obj.poly[0].pow == 1) {
                out << 'x';
            } else if (obj.poly[0].pow != 0) {
                out << "x^" << obj.poly[0].pow;
            }
        }
        for (int i = 1; i < obj.poly.getSize(); ++i) {
            if (obj.poly[i].koef == 0) { continue; }
            if (obj.poly[i].koef > 0) { out << " + "; }
            if (obj.poly[i].koef < 0) { out << " - "; }
            if (abs(obj.poly[i].koef) != 1) {
                out << abs(obj.poly[i].koef);
            }
            if (obj.poly[i].pow == 0) {
                continue;
            }
            if (obj.poly[i].pow == 1) {
                out << 'x';
                continue;
            }
            out << "x^" << obj.poly[i].pow;
        }
        out << '\n';
        return out;
    }
    friend std::istream &operator>>(std::istream &in, MyPolynomial &obj) {
        char inputString[kSize];
        in.getline(inputString, kSize);
        strcat(inputString, "+");
        char tmpString[kSize];
        strcpy(tmpString, "");
        MyTerm tmp;
        int i = 0;
        bool flag = false;
        while(i < strlen(inputString)) {
            if (((inputString[i] - '0') >= 0 && (inputString[i] - '0') <= 9) || inputString[i] == 'x') {
                flag = true;
            }
            if ((inputString[i] == '-' || inputString[i] == '+') && flag) {
                tmp = MyTerm(tmpString);
                obj += tmp;
                strcpy(tmpString, "");
            }
            char tmpSymbol[2];
            tmpSymbol[0] = inputString[i];
            tmpSymbol[1] = '\0';
            if (inputString[i] != '+') {
                strcat(tmpString, tmpSymbol);
            }
            ++i;
        }

        obj.poly.sort(obj.order);
        return in;
    }
};
