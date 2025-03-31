#pragma once

#include <fstream>
#include <iostream>

class Article {
private:
  char *name = nullptr;
  int number = 0;
  int views = 0;
  int likes = 0;

public:
  Article(); // тривиальный конструктор
  Article(const char *name1, const int number1, const int views1,
         const int likes1); // конструктор
  Article(const Article &other); // конструктор копирования
  ~Article();                   // деструктор

  char *getName();
  int getNumber();
  int getViews();
  int getLikes();

  void setName(const char *name1);
  void setNumber(const int number1);
  void setViews(const int views1);
  void setLikes(const int likes1);

  friend std::ostream &operator<<(std::ostream &out, const Article &obj);
  friend std::istream &operator>>(std::istream &in, Article &obj);

  friend std::ofstream &operator<<(std::ofstream &out, const Article &obj);
  friend std::ifstream &operator>>(std::ifstream &in, Article &obj);

  bool operator<(const Article &obj);
  bool operator==(const Article &obj);
  Article& operator=(const Article &obj);

  // сортировка БД;
  static void sortList(Article*& list, int size);
  // добавление нового объекта в БД;
  static void pushObj(Article*& list, int &size, Article obj);
  // удаление объекта из БД;
  static void deleteObj(Article*& list, int &size, char *objName);
  // вывод БД на экран.
  static void printList(Article* list, int size);
  // чтение БД из файла
  static void readFromFile(Article*& list, int &size, const char* fileName);
  // запись БД в файл;
  static void writeToFile(Article* list, int size, const char* fileName);
  // редактирование БД;
  static void editObjName(Article*& list, int size, char *objName, char *newName);
  static void editObjNumber(Article*& list, int size, char *objName,
                              int newNumber);
  static void editObjViews(Article*& list, int size, char *objName,
                                int newViews);
  static void editObjLikes(Article*& list, int size, char *objName, int newLikes);
};
