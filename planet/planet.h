#pragma once

#include <fstream>
#include <iostream>

class Planet {
private:
  char *name = nullptr;
  int diameter = 0;
  bool life = false;
  int satellites = 0;

public:
  Planet(); // тривиальный конструктор
  Planet(const char *name1, const int diameter1, const bool life1,
         const int satellites1); // конструктор
  Planet(const Planet &other); // конструктор копирования
  ~Planet();                   // деструктор

  char *getName();
  int getDiameter();
  bool getLife();
  int getSatellites();

  void setName(const char *name1);
  void setDiameter(const int diameter1);
  void setLife(const bool life1);
  void setSatellites(const int satellites1);

  friend std::ostream &operator<<(std::ostream &out, const Planet &obj);
  friend std::istream &operator>>(std::istream &in, Planet &obj);

  friend std::ofstream &operator<<(std::ofstream &out, const Planet &obj);
  friend std::ifstream &operator>>(std::ifstream &in, Planet &obj);

  bool operator>(const Planet &obj);
  bool operator==(const Planet &obj);
  Planet& operator=(const Planet &obj);

  // сортировка БД;
  static void sortList(Planet*& list, int size);
  // добавление нового объекта в БД;
  static void pushObj(Planet*& list, int &size, Planet obj);
  // удаление объекта из БД;
  static void deleteObj(Planet*& list, int &size, char *objName);
  // вывод БД на экран.
  static void printList(Planet* list, int size);
  // чтение БД из файла
  static void readFromFile(Planet*& list, int &size, const char* fileName);
  // запись БД в файл;
  static void writeToFile(Planet* list, int size, const char* fileName);
  // редактирование БД;
  static void editObjName(Planet*& list, int size, char *objName, char *newName);
  static void editObjDiameter(Planet*& list, int size, char *objName,
                              int newDiameter);
  static void editObjSatellites(Planet*& list, int size, char *objName,
                                int newSatellites);
  static void editObjLife(Planet*& list, int size, char *objName, bool newLife);
};
