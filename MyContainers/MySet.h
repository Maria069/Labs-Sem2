#pragma once
#include <iostream>

#include "MyVector.h"

template<class DATA>
class MySet : protected MyVector<DATA> {
  using MyVector<DATA>::size;
  using MyVector<DATA>::vector;
  using MyVector<DATA>::add_element;
  using MyVector<DATA>::delete_element;
  using MyVector<DATA>::find;
  using MyVector<DATA>::sort;
 public:
  MySet() : MyVector<DATA>() {}
  MySet(DATA elem) : MyVector<DATA>() { add_element(elem); }
  MySet(MySet &obj) : MyVector<DATA>(obj) {}
  MySet &operator=(MySet &obj) {
    if (this == &obj) return *this;
    MyVector<DATA>::operator=(obj);
    return *this;
  }

  bool operator==(MySet &s) {
    if (size != s.size) { return false; }
    for (int i = 0; i < size; ++i) {
      if (!s.is_element(vector[i])) { return false; }
    }
    return true;
  }
  MySet &operator+=(MySet &s) {
    for (int i = 0; i < s.size; ++i) {
      add_element(s.vector[i]);
    }
    return *this;
  }
  MySet &operator-=(MySet &s) {
    for (int i = 0; i < s.size; ++i) {
      while (is_element(s.vector[i])) {
        delete_element(s.vector[i]);
      }
    }
    return *this;
  }
  MySet &operator*=(MySet &s) {
    MySet<DATA> temp;
    for (int i = 0; i < size; ++i) {
      if (s.is_element(vector[i])) {
        temp.MySet<DATA>::add_element(vector[i]);
      }
    }
    *this = temp;
    return *this;
  }
  void add_element(DATA elem) {
    if (!is_element(elem)) {
        MyVector<DATA>::add_element(elem);
        sort();
    }
  }
  void delete_element(DATA el) {
    sort();
    int i = find(el);
    if (0 <= i && i < size && vector[i] == el) {
      MyVector<DATA>::delete_element(i);
    }
  }
  bool is_element(DATA el) {
    sort();
    int i = find(el);
    return (0 <= i && i < size && vector[i] == el);
  }
  friend std::ostream &operator<<(std::ostream &out, const MySet &s) {
    out << '{';
    for (int i = 0; i < s.size; ++i) {
      out << s.vector[i];
      if (i != s.size - 1) {
        out << ", ";
      }
    }
    out << '}' << '\n';
    return out;
  }
  friend MySet operator+(MySet &s1, MySet &s2) {
    MySet<DATA> result = s1;
    result += s2;
    return result;
  }
  friend MySet operator-(MySet &s1, MySet &s2) {
    MySet<DATA> result = s1;
    result -= s2;
    return result;
  }
  friend MySet operator*(MySet &s1, MySet &s2) {
    MySet<DATA> result = s1;
    result *= s2;
    return result;
  }
};

template<>
bool MySet<char*>::is_element(char* el) {
    sort();
    int i = find(el);
    return (0 <= i && i < size && strcmp(vector[i], el) == 0);
}
template<>
void MySet<char*>::delete_element(char* el) {
    sort();
    int i = find(el);
    if (0 <= i && i < size && strcmp(vector[i], el) == 0) {
        MyVector<char*>::delete_element(i);
    }
}
