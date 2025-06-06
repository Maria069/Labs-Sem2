#pragma once
#include <iostream>

const int DefaultSize = 2;

template<class DATA>
class MyVector {
 protected:
  int capacity = DefaultSize;
  int size = 0;
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
  MyVector(const MyVector &obj) {
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
  DATA operator[](int index) {
    return vector[index];
  }
  DATA operator[](int index) const {
    return vector[index];
  }

  void sort() {
    bool sorted = false;
    for (int i = 0; i < size - 1 && !sorted; ++i) {
      sorted = true;
      for (int j = 0; j < size - i - 1; ++j) {
        if (vector[j] > vector[j + 1]) {
          DATA tmp = vector[j];
          vector[j] = vector[j + 1];
          vector[j + 1] = tmp;
          sorted = false;
        }
      }
    }
  }

  int getSize() const { return size; }
  int getCapacity() const { return capacity; }
  int find(DATA elem) {
    int l = 0;
    int r = size;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (vector[m] <= elem) {
        l = m;
      } else {
        r = m;
      }
    }
    if (vector[l] != elem) {
      return -1;
    }
    return l;
  }

  MyVector &operator=(MyVector &obj) {
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
    out << '[';
    for (int i = 0; i < v.size; ++i) {
      out << v.vector[i];
      if (i != v.size - 1) {
        out << ", ";
      }
    }
    out << ']' << '\n';
    return out;
  }
};


template<>
MyVector<char*>::MyVector(int size1) {
  capacity = DefaultSize;
  if (size1 > capacity) {
    capacity = size1;
  }
  size = size1;
  vector = new char*[capacity];
}

template<>
MyVector<char*>::~MyVector() {
  for (int i = 0; i < size; ++i) {
    free(vector[i]);
  }
  delete[] vector;
}

template<>
MyVector<char*>::MyVector(const MyVector<char*> &obj) {
  capacity = obj.capacity;
  size = obj.size;

  vector = new char*[size];
  for (int i = 0; i < size; ++i) {
    //strcpy(vector[i], obj.vector[i]);
    vector[i] = strdup(obj.vector[i]);
  }
}

template<>
MyVector<char*> &MyVector<char*>::operator=(MyVector<char*> &obj) {
  if (this == &obj) {
    return *this;
  }
  for (int i = 0; i < size; ++i) {
    free(vector[i]);
  }
  delete[] vector;
  capacity = obj.capacity;
  size = obj.size;
  vector = new char*[size];
  for (int i = 0; i < size; ++i) {
    //strcpy(vector[i], obj.vector[i]);
    vector[i] = strdup(obj.vector[i]);
  }
  return *this;
}

template<>
void MyVector<char*>::sort() {
  bool sorted = false;
  for (int i = 0; i < size - 1 && !sorted; ++i) {
    sorted = true;
    for (int j = 0; j < size - i - 1; ++j) {
      if (strcmp(vector[j], vector[j + 1]) > 0) {
        char* tmp = vector[j];
        vector[j] = vector[j + 1];
        vector[j + 1] = tmp;
        sorted = false;
      }
    }
  }
}

template<>
int MyVector<char*>::find(char* elem) {
  int l = 0;
  int r = size;
  while (r - l > 1) {
    int m = (l + r) / 2;
    if (strcmp(vector[m], elem) <= 0) {
      l = m;
    } else {
      r = m;
    }
  }
  if (l < size && strcmp(vector[l], elem) == 0) {
    return l;
  }
  return -1;
}

template<>
void MyVector<char*>::add_element(char* elem) {
    if (size >= capacity) {
        resize();
    }
    //strcpy(vector[size++], elem + '\0');
    vector[size++] = strdup(elem);
}

template<>
bool MyVector<char*>::delete_element(int index) {
  if (size <= index) {
    return false;
  }
  for (int i = index; i < size - 1; ++i) {
    vector[i] = strdup(vector[i + 1]);
  }
  --size;
  return true;
}
