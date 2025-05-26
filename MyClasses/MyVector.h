#pragma once
#include <iostream>

const int DefaultSize = 1;

template<class DATA>
class MyVector {
 protected:
  int capacity;
  int size;
  DATA* vector;

 public:
  MyVector(int size1 = 0) {
    capacity = DefaultSize;
    if (size1 > capacity) {
      capacity = size1;
    }
    size = size1;
    DATA* tmp = new DATA[capacity];
    vector = tmp;
  }
  MyVector(MyVector &obj) {
    capacity = obj.capacity;
    size = obj.size;

    DATA* buffer = new DATA[size];
    for (int i = 0; i < size; ++i) {
      buffer[i] = obj.vector[i];
    }
    vector = buffer;
  }
  ~MyVector() {
    delete[] vector;
  }
  void resize() {
    int newSize = capacity * 2;
    DATA* buffer = new DATA[newSize];

    std::copy(vector, vector + size, buffer);

    DATA* oldVector = vector;
    vector = buffer;
    capacity = newSize;

    delete[] oldVector;
  }
  void add_element(DATA elem) {
    if (size >= capacity) {
      resize();
    }
    vector[size++] = elem;
  }
  bool delete_element(int index) {
    if (size <= index) {
      return false;
    }
    for (int i = index; i < size - 1; ++i) {
      vector[i] = vector[i + 1];
    }
    --size;
    return true;
  }
  DATA& operator[](int index) {
    return vector[index];
  }
  DATA operator[]  (int index) const {
    return vector[index];
  }
  void sort(bool flag) {
    bool sorted = false;
    for (int i = 0; i < size - 1 && !sorted; ++i) {
      sorted = true;
      for (int j = 0; j < size - i - 1; ++j) {
        if ((vector[j] > vector[j + 1])^flag) {
          DATA tmp = vector[j];
          vector[j] = vector[j + 1];
          vector[j + 1] = tmp;
          sorted = false;
        }
      }
    }
  }
  int getSize() const { return size; }
  int getCapacity() { return capacity; }
  int find(DATA elem) {
    int l = 0;
    int r = size + 1;

    while (r - l > 1) {
      int m = (l + r) / 2;
      if (vector[m] <= elem) {
        l = m;
      } else {
        r = m;
      }
    }

    if (vector[l] != elem) {
      std::cout << "Нет такого элемента\n";
    }
    return l;
  }
  MyVector &operator=(const MyVector &obj) {
    if (this == &obj) {
      return *this;
    }
    delete[] vector;
    capacity = obj.capacity;
    size = obj.size;
    DATA* buffer = new DATA[size];
    for (int i = 0; i < size; ++i) {
      buffer[i] = obj.vector[i];
    }
    vector = buffer;
    return *this;
  }
  friend std::ostream &operator<<(std::ostream &out, MyVector &v) {
    for (int i = 0; i < v.size; ++i) {
      out << v[i] << ' ';
    }
    out << '\n';
    return out;
  }
};
