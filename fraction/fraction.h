#pragma once

#include <fstream>
#include <iostream>

int NOD(int a, int b);
int NOK(int a, int b);
// сокращение;
void reduceFraction(int& numerator, int& denominator);

class Fraction {
private:
  int numerator = 0;
  int denominator = 1;

public:
  Fraction(); // тривиальный конструктор
  Fraction(char *fraction1); // конструктор
  Fraction(int numerator1, int denominator1);
  Fraction(double fraction1);
  Fraction(const Fraction &other); // конструктор копирования
  ~Fraction(); // деструктор

  int getNumerator();
  int getDenominator();

  void setNumerator(const int numerator1);
  void setDenominator(const int denominator1);

  friend std::ostream &operator<<(std::ostream &out, Fraction &obj);
  friend std::istream &operator>>(std::istream &in, Fraction &obj);

  //=
  //Fraction& operator=(Fraction& obj);

  //+= +
  Fraction operator+(const Fraction& obj);
  Fraction operator+=(const Fraction& obj);

  Fraction operator+(int x);
  Fraction operator+(double x);

  friend Fraction operator+(int x, const Fraction& obj);
  friend Fraction operator+(double x, const Fraction& obj);

  Fraction operator+=(int x);
  Fraction operator+=(double x);
};
