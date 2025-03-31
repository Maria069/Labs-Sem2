#include "article.h"
#include <fstream>
#include <iostream>

Article::Article() { name = new char[1]; } // тривиальный конструктор
Article::Article(const char *name1, const int number1, const int views1,
               const int likes1) { // конструктор
  name = new char[strlen(name1) + 1];
  strcpy(name, name1);
  name[strlen(name1) + 1] = '\0';
  number = number1;
  views = views1;
  likes = likes1;
}
Article::Article(const Article &other) { // конструктор копирования
  name = new char[strlen(other.name) + 1];
  strcpy(name, other.name);
  number = other.number;
  views = other.views;
  likes = other.likes;
}
Article::~Article() { delete[] name; } // деструктор

char *Article::getName() { return name; }
int Article::getNumber() { return number; }
int Article::getViews() { return views; }
int Article::getLikes() { return likes; }

void Article::setName(const char *name1) {
  name = new char[strlen(name1) + 1];
  strcpy(name, name1);
  name[strlen(name1) + 1] = '\0';
}
void Article::setNumber(const int number1) { number = number1; }
void Article::setViews(const int views1) { views = views1; }
void Article::setLikes(const int likes1) { likes = likes1; }

//сравнение
bool Article::operator<(const Article &obj) {
  if (views != obj.views) {
    return views < obj.views;
  }
  if (likes != obj.likes) {
    return likes < obj.likes;
  }
  return number < obj.number;
}

bool Article::operator==(const Article &obj) {
  return (name == obj.name) && (number == obj.number) && (views == obj.views) && (likes == obj.likes);
}

Article& Article::operator=(const Article &obj) {
  if (this == &obj) {
    return *this;
  }
  setName(obj.name);
  setNumber(obj.number);
  setViews(obj.views);
  setLikes(obj.likes);
  return *this;
}

// ввод вывод
std::ostream &operator<<(std::ostream &out, const Article &obj) {
  out << obj.name << ' ' << obj.number << ' ' << obj.views << ' '
      << obj.likes << '\n';
  return out;
}
std::istream &operator>>(std::istream &in, Article &obj) {
  char name[30];
  in >> name >> obj.number >> obj.views >> obj.likes;
  obj.setName(name);
  return in;
}

// ввод вывод в файл
std::ofstream &operator<<(std::ofstream &out, const Article &obj) {
  out << obj.name << ' ' << obj.number << ' ' << obj.views << ' '
      << obj.likes << '\n';
  return out;
}
std::ifstream &operator>>(std::ifstream &in, Article &obj) {
  char name[30];
  in >> name >> obj.number >> obj.views >> obj.likes;
  obj.setName(name);
  return in;
}

// сортировка БД;
void Article::sortList(Article*& list, int size) {
  bool sorted = false;
  for (int i = 0; i < size - 1 && !sorted; ++i) {
    sorted = true;
    for (int j = 0; j < size - i - 1; ++j) {
      if (list[j] < list[j + 1]) {
        // Article obj = list[j + 1];
        // list[j + 1] = list[j];
        // list[j] = obj;
        std::swap(list[j + 1], list[j]);
        sorted = false;
      }
    }
  }
  std::cout << "Список статей отсортирован по популярности\n";
}
// добавление нового объекта в БД;
void Article::pushObj(Article*& list, int& size, Article obj) {
  Article *newList = new Article[size + 1];
  for (int i = 0; i < size; ++i) {
    newList[i] = list[i];
  }
  newList[size] = obj;
  delete[] list;
  list = newList;
  size++;
}
// удаление объекта из БД;
void Article::deleteObj(Article*& list, int &size, char *objName) {
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
    std::cout << "Статья с таким именем не найдена\n";
    return;
  }

  Article *newList = new Article[size - 1];
  for (int i = 0, j = 0; i < size; ++i) {
    if (i != index) {
      newList[j++] = list[i];
    }
  }

  delete[] list;
  list = newList;
  size--;
  std::cout << "Статья удалена\n";
}

// вывод БД на экран
void Article::printList(Article* list, int size) {
  std::cout << "Текущий список статей:\n";
  if (!list) {
    return;
  }
  for (int i = 0; i < size; ++i) {
    std::cout << list[i];
  }
}

// чтение БД из файла;
void Article::readFromFile(Article*& list, int &size, const char* fileName) {
  std::ifstream file(fileName);
  Article obj;
  if (list) {
    delete[] list;
  }
  if (!file) {
    return;
  }
  file >> size;
  list = new Article[size];
  for (int i = 0; i < size; ++i) {
    file >> list[i];
  }
  file.close();
  std::cout << "Файл прочитан\n";
}

// запись БД в файл;
void Article::writeToFile(Article* list, int size, const char* fileName) {
  std::ofstream file(fileName, std::ios::trunc);
  file << size << '\n';
  for (int i = 0; i < size; ++i) {
    file << list[i];
  }
  file.close();
  std::cout << "Список сохранен в файл\n";
}

// редактирование БД;
void Article::editObjName(Article*& list, int size, char *objName, char *newName) {
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
void Article::editObjNumber(Article*& list, int size, char *objName, int newNumber) {
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
    std::cout << "Статья с таким именем не найдена\n";
    return;
  }
  list[index].setNumber(newNumber);
}
void Article::editObjViews(Article*& list, int size, char *objName, int newViews) {
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
    std::cout << "Статья с таким именем не найдена\n";
    return;
  }
  list[index].setViews(newViews);
}
void Article::editObjLikes(Article*& list, int size, char *objName, int newLikes) {
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
    std::cout << "Статья с таким именем не найдена\n";
    return;
  }
  list[index].setLikes(newLikes);
}
