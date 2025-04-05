#include "Application.h"
#include "fraction/fraction.h"

#include <fstream>
#include <iostream>

namespace Application {
void StartApp() {
  // //конструкторы
  // Fraction f1("1 2/3");
  // std::cout << f1;

  // Fraction f2(1.23456);
  // std::cout << f2;

  // Fraction f3(34, 56);
  // std::cout << f3;

  // // ввод с клавиатуры
  // std::cout << "Введите дробь: \n";
  // Fraction f;
  // std::cin >> f;
  // std::cout << f;

  // //сложение
  // int a = 5;
  // double b = 1.23;

  // f1 += a;
  // f2 += b;
  // std::cout << f1 << f2;

  // f1 += f2;
  // std::cout << f1;

  // ввод дроби с клавиатуры
    std::cout << "Введите дробь: \n";
    Fraction z;
    std::cin >> z;
    std::cout << "z=" << z << std::endl;
    // проверка конструкторов
    Fraction fr1(10, 14), fr2;
    std::cout << "fr2=" << fr2 << std::endl;
    std::cout << "fr1=" << fr1 << std::endl;
    Fraction fr = "-1 4/8";
    std::cout << "fr=" << fr << std::endl;
    Fraction x(z), y;
    std::cout << "x=" << x << std::endl;
    double dbl = -1.25;
    Fraction f = dbl;
    std::cout << "f=" << f << std::endl;
    // проверка перегруженной операции "+"
    y = x + z;
    std::cout << "y=" << y << std::endl;
    y += x;
    f += dbl / 2;
    std::cout << "f=" << f << std::endl;
    y = x + dbl;
    std::cout << "y=" << y << std::endl;
    y = dbl + y;
    std::cout << "y=" << y << std::endl;
    y += dbl;
    std::cout << "y=" << y << std::endl;
    int i = 5;
    y += i;
    std::cout << "y=" << y << std::endl;
    y = i + x;
    std::cout << "y=" << y << std::endl;
    y = x + i;
    std::cout << "y=" << y << std::endl;
    y += dbl + i + x;
    std::cout << "y=" << y << std::endl;
}
} // namespace Application