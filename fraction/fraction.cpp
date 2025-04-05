#include "fraction.h"
#include <iostream>

namespace {
  const int kAccuracy = 1e4;
  const int kSize = 500;
  const int kDec = 10;
} // namespace

int NOD(int a, int b) {
  if (b == 0) {
    return a;
  }
  return NOD(b, a % b);
}

int NOK(int a, int b) {
  return a * b / NOD(a, b);
}

// сокращение;
void reduceFraction(int& numerator, int& denominator) {
  if (denominator == 0) {
    std::cout << "А ниче тот факт что у вас знаменатель ноль?\n";
    exit(0);
  }
  int fractionNOD = NOD(std::abs(numerator), std::abs(denominator));
  if (fractionNOD > 1) {
    numerator /= fractionNOD;
    denominator /= fractionNOD;
  }
}

Fraction::Fraction() {} // тривиальный конструктор
Fraction::Fraction(char *fraction1) { // конструктор 1
  int intPart = 0;
  numerator = 0;
  denominator = 0;
  int i = 0;
  bool checker = false;
  bool sign = false;
  if (fraction1[i] == '-')  {
    sign = true;
    ++i;
  }
  while (fraction1[i] != '\0') {
    if (fraction1[i] == ' ') {
      intPart = abs(std::stoi(fraction1));
      ++i;
      break;
    }
    ++i;
  }
  if (fraction1[i] == '\0') {
    i = 0;
    if (sign) {
      ++i;
    }
  }
  while (fraction1[i] != '\0') {
    if (fraction1[i] == '/') {
      checker = true;
    } else {
      if (!checker) {
          numerator *= kDec;
          numerator += (fraction1[i] - '0');
      } else {
          denominator *= kDec;
          denominator += (fraction1[i] - '0');
      }
    }
    ++i;
  }
  if (denominator == 0 && !checker) {
    denominator = 1;
  }
  numerator += intPart * denominator;
  if (sign) {
    numerator *= -1;
  }
  //std::cout << numerator << ' ' << denominator << '\n';
  reduceFraction(numerator, denominator);
}
Fraction::Fraction(int numerator1, int denominator1) { // конструктор 2
  numerator = numerator1;
  denominator = denominator1;
  reduceFraction(numerator, denominator);
}
Fraction::Fraction(double fraction1) { // конструктор 3
  denominator = kAccuracy;
  numerator = int(fraction1 * denominator);
  reduceFraction(numerator, denominator);
}

Fraction::Fraction(const Fraction &other) { // конструктор копирования
  numerator = other.numerator;
  denominator = other.denominator;
  reduceFraction(numerator, denominator);
}
Fraction::~Fraction() {} // деструктор


int Fraction::getNumerator() { return numerator; }
int Fraction::getDenominator() { return denominator; }

void Fraction::setNumerator(const int numerator1) {
  numerator = numerator1;
  reduceFraction(numerator, denominator);
}
void Fraction::setDenominator(const int denominator1) {
  denominator = denominator1;
  reduceFraction(numerator, denominator);
}

// Fraction& Fraction::operator=(Fraction& obj) {
//   if (this == &obj) {
//     return *this;
//   }
//   numerator = obj.numerator;
//   denominator = obj.denominator;
//   reduceFraction(numerator, denominator);
//   return *this;
// }

std::ostream &operator<<(std::ostream &out, Fraction &obj) {
  reduceFraction(obj.numerator, obj.denominator);
  if (obj.denominator == 1) {
    out << obj.numerator << '\n';
    return out;
  }
  if (abs(obj.numerator) > abs(obj.denominator)) {
    int intPart = obj.numerator / obj.denominator;
    out << intPart << ' ' << abs(obj.numerator) - abs(intPart * obj.denominator) << '/' << obj.denominator << '\n';
    return out;
  }
  out << obj.numerator << '/' << obj.denominator << '\n';
  return out;
}
std::istream &operator>>(std::istream &in, Fraction &obj) {
 char inputString[kSize];
 in.getline(inputString, '\n');
 Fraction temp(inputString);
 obj.numerator = temp.numerator;
 obj.denominator = temp.denominator;
 return in;
}

//+= +
Fraction Fraction::operator+(const Fraction& obj) {
  int fractionNOK = NOK(denominator, obj.denominator);
  return Fraction((fractionNOK / denominator) * numerator + (fractionNOK / obj.denominator) * obj.numerator, fractionNOK);
}
Fraction Fraction::operator+=(const Fraction& obj) {
  int fractionNOK = NOK(denominator, obj.denominator);
  numerator = (fractionNOK / denominator) * numerator + (fractionNOK / obj.denominator) * obj.numerator;
  denominator = fractionNOK;
  return *this;
}

Fraction Fraction::operator+(int x) {
  return Fraction(numerator + (denominator * x), denominator);
}
Fraction Fraction::operator+(double x) {
  Fraction temp(x);
  return (temp + *this);
}

Fraction operator+(int x, const Fraction& obj) {
  return Fraction(obj.numerator + (obj.denominator * x), obj.denominator);
}
Fraction operator+(double x, const Fraction& obj) {
  Fraction temp(x);
  return (temp + obj);
}

Fraction Fraction::operator+=(int x) {
  numerator += (denominator * x);
  return *this;
}
Fraction Fraction::operator+=(double x) {
  Fraction temp(x);
  *this += temp;
  return *this;
}
