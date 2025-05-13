#pragma once
#include <iostream>

#include "MyVector.h"

template<class DATA>
class MySet : protected MyVector {
 public:
  MySet();
  MySet(DATA elem) : MyVector<DATA>(elem) {};
  MySet(MySet &obj) : MyVector<DATA>(obj) {};

  bool operator==(MySet &s) {
    bool flag = true;
    int i = 0;
    int j = 0;
    while (i < size && j < s.size) {
      
    }
    return flag;
  }
  MySet &operator+=(MySet &s);
  MySet &operator-=(MySet &s);
  MySet &operator*=(MySet &s);
  void add_element(DATA el);
  void delete_element(DATA el);
  bool is_element(DATA el);
  friend std::ostream &operator<<(std::ostream &out, MySet &s);
  friend MySet operator+(MySet &s1, MySet &s2);
  friend MySet operator-(MySet &s1, MySet &s2);
  friend MySet operator*(MySet &s1, MySet &s2);
};
