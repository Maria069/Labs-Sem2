#pragma once
#include <iostream>

const int MAX_SIZE = 5;

class MyVector {
 protected:
  int max_size;
  int size;
  char **pdata;
  void resize();

 public:
  MyVector(char *el = NULL, int max_size = MAX_SIZE);
  MyVector(MyVector &v);
  ~MyVector();
  void add_element(char *el);
  bool delete_element(int i);
  char *operator[](int i);
  void sort();
  int get_size() { return size; }
  int get_max_size() { return max_size; }
  int find(char *el);
  MyVector &operator=(MyVector &v);
  friend std::ostream &operator<<(std::ostream &out, MyVector &v);
};
