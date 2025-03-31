#include "planet.h"
#include <fstream>
#include <iostream>

Planet::Planet() { name = new char[1]; } // тривиальный конструктор
Planet::Planet(const char *name1, const int diameter1, const bool life1,
               const int satellites1) { // конструктор
  name = new char[strlen(name1) + 1];
  strcpy(name, name1);
  name[strlen(name1) + 1] = '\0';
  diameter = diameter1;
  life = life1;
  satellites = satellites1;
}
Planet::Planet(const Planet &other) { // конструктор копирования
  name = new char[strlen(other.name) + 1];
  strcpy(name, other.name);
  diameter = other.diameter;
  life = other.life;
  satellites = other.satellites;
}
Planet::~Planet() { delete[] name; } // деструктор

char *Planet::getName() { return name; }
int Planet::getDiameter() { return diameter; }
bool Planet::getLife() { return life; }
int Planet::getSatellites() { return satellites; }

void Planet::setName(const char *name1) {
  name = new char[strlen(name1) + 1];
  strcpy(name, name1);
  name[strlen(name1) + 1] = '\0';
}
void Planet::setDiameter(const int diameter1) { diameter = diameter1; }
void Planet::setLife(const bool life1) { life = life1; }
void Planet::setSatellites(const int satellites1) { satellites = satellites1; }

//сравнение
bool Planet::operator>(const Planet &obj) {
  if (diameter != obj.diameter) {
    return diameter > obj.diameter;
  }
  return satellites > obj.satellites;
}

bool Planet::operator==(const Planet &obj) {
  return (name == obj.name) && (diameter == obj.diameter) && (life == obj.life) && (satellites == obj.satellites);
}

Planet& Planet::operator=(const Planet &obj) {
  if (this == &obj) {
    return *this;
  }
  setName(obj.name);
  setDiameter(obj.diameter);
  setLife(obj.life);
  setSatellites(obj.satellites);
  return *this;
}

// ввод вывод
std::ostream &operator<<(std::ostream &out, const Planet &obj) {
  out << obj.name << ' ' << obj.diameter << ' ' << obj.life << ' '
      << obj.satellites << '\n';
  return out;
}
std::istream &operator>>(std::istream &in, Planet &obj) {
  char name[30];
  in >> name >> obj.diameter >> obj.life >> obj.satellites;
  obj.setName(name);
  return in;
}

// ввод вывод в файл
std::ofstream &operator<<(std::ofstream &out, const Planet &obj) {
  out << obj.name << ' ' << obj.diameter << ' ' << obj.life << ' '
      << obj.satellites << '\n';
  return out;
}
std::ifstream &operator>>(std::ifstream &in, Planet &obj) {
  char name[30];
  in >> name >> obj.diameter >> obj.life >> obj.satellites;
  obj.setName(name);
  return in;
}

// сортировка БД;
void Planet::sortList(Planet*& list, int size) {
  bool sorted = false;
  for (int i = 0; i < size - 1 && !sorted; ++i) {
    sorted = true;
    for (int j = 0; j < size - i - 1; ++j) {
      if (list[j] > list[j + 1]) {
        Planet obj = list[j + 1];
        list[j + 1] = list[j];
        list[j] = obj;
        sorted = false;
      }
    }
  }
  std::cout << "Список планет отсортирован\n";
}
// добавление нового объекта в БД;
void Planet::pushObj(Planet*& list, int& size, Planet obj) {
  Planet *newList = new Planet[size + 1];
  for (int i = 0; i < size; ++i) {
    newList[i] = list[i];
  }
  newList[size] = obj;
  delete[] list;
  list = newList;
  size++;
}
// удаление объекта из БД;
void Planet::deleteObj(Planet*& list, int &size, char *objName) {
  if (size == 0) {
    std::cout << "Список пуст\n";
    return;
  }

  int index = -1;
  for (int i = 0; i < size; ++i) {
    if (!std::strcmp(list[i].getName(), objName)) {
      index = i;
      break;
    }
  }

  if (index == -1) {
    std::cout << "Планета с таким именем не найдена\n";
    return;
  }

  Planet *newList = new Planet[size - 1];
  for (int i = 0, j = 0; i < size; ++i) {
    if (i != index) {
      newList[j++] = list[i];
    }
  }

  delete[] list;
  list = newList;
  size--;
  std::cout << "Планета удалена\n";
}

// вывод БД на экран
void Planet::printList(Planet* list, int size) {
  std::cout << "Текущий список планет:\n";
  if (!list) {
    return;
  }
  for (int i = 0; i < size; ++i) {
    std::cout << list[i];
  }
}

// чтение БД из файла;
void Planet::readFromFile(Planet*& list, int &size, const char* fileName) {
  std::ifstream file(fileName);
  Planet obj;
  if (list) {
    delete[] list;
  }
  if (!file) {
    return;
  }
  file >> size;
  list = new Planet[size];
  for (int i = 0; i < size; ++i) {
    file >> list[i];
  }
  file.close();
  std::cout << "Файл прочитан\n";
}

// запись БД в файл;
void Planet::writeToFile(Planet* list, int size, const char* fileName) {
  std::ofstream file(fileName, std::ios::trunc);
  file << size << '\n';
  for (int i = 0; i < size; ++i) {
    file << list[i];
  }
  file.close();
  std::cout << "Список сохранен в файл\n";
}

// редактирование БД;
void Planet::editObjName(Planet*& list, int size, char *objName, char *newName) {
  if (size == 0) {
    std::cout << "Список пуст\n";
    return;
  }
  int index = -1;
  for (int i = 0; i < size; ++i) {
    if (!std::strcmp(list[i].getName(), objName)) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    std::cout << "Планета с таким именем не найдена\n";
    return;
  }
  list[index].setName(newName);
}
void Planet::editObjDiameter(Planet*& list, int size, char *objName, int newDiameter) {
  if (size == 0) {
    std::cout << "Список пуст\n";
    return;
  }
  int index = -1;
  for (int i = 0; i < size; ++i) {
    if (!std::strcmp(list[i].getName(), objName)) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    std::cout << "Планета с таким именем не найдена\n";
    return;
  }
  list[index].setDiameter(newDiameter);
}
void Planet::editObjSatellites(Planet*& list, int size, char *objName,
                       int newSatellites) {
  if (size == 0) {
    std::cout << "Список пуст\n";
    return;
  }
  int index = -1;
  for (int i = 0; i < size; ++i) {
    if (!std::strcmp(list[i].getName(), objName)) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    std::cout << "Планета с таким именем не найдена\n";
    return;
  }
  list[index].setSatellites(newSatellites);
}
void Planet::editObjLife(Planet*& list, int size, char *objName, bool newLife) {
  if (size == 0) {
    std::cout << "Список пуст\n";
    return;
  }
  int index = -1;
  for (int i = 0; i < size; ++i) {
    if (!std::strcmp(list[i].getName(), objName)) {
      index = i;
      break;
    }
  }
  if (index == -1) {
    std::cout << "Планета с таким именем не найдена\n";
    return;
  }
  list[index].setLife(newLife);
}
