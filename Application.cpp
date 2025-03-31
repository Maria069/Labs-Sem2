#include "Application.h"
#include "article/article.h"
#include "planet/planet.h"

#include <fstream>
#include <iostream>

namespace Application {
void ChoseEditPlanetPlace(Planet* list, int size, char *objName) {
  std::cout
      << "Выберете редактируемое поле и введите соответствующую цифру: \n";
  std::cout << "1 - Имя\n";
  std::cout << "2 - Диаметр\n";
  std::cout << "3 - Население\n";
  std::cout << "4 - Спутники\n";

  int action = 0;
  std::cin >> action;

  switch (action) {
  case 1: {
    char newName[30];
    std::cout << "Введите новое имя\n";
    std::cin >> newName;
    Planet::editObjName(list, size, objName, newName);
    break;
  }
  case 2: {
    int newDiameter;
    std::cout << "Введите новое значение диаметра\n";
    std::cin >> newDiameter;
    Planet::editObjDiameter(list, size, objName, newDiameter);
    break;
  }
  case 3: {
    bool newLife;
    std::cout << "Введите новое значение для населения\n";
    std::cin >> newLife;
    Planet::editObjDiameter(list, size, objName, newLife);
    break;
  }
  case 4: {
    int newSatellites;
    std::cout << "Введите новое число спутников\n";
    std::cin >> newSatellites;
    Planet::editObjDiameter(list, size, objName, newSatellites);
    break;
  }
  default: {
    std::cout << "Тип действия выбран некорректно\n";
    break;
  }
  }
}

void ChoseEditArticlePlace(Article* list, int size, char *objName) {
  std::cout
      << "Выберете редактируемое поле и введите соответствующую цифру: \n";
  std::cout << "1 - Имя\n";
  std::cout << "2 - Номер\n";
  std::cout << "3 - Просмотры\n";
  std::cout << "4 - Лайки\n";

  int action = 0;
  std::cin >> action;

  switch (action) {
  case 1: {
    char newName[30];
    std::cout << "Введите новое имя\n";
    std::cin >> newName;
    Article::editObjName(list, size, objName, newName);
    break;
  }
  case 2: {
    int newNumber;
    std::cout << "Введите новый номер статьи\n";
    std::cin >> newNumber;
    Article::editObjNumber(list, size, objName, newNumber);
    break;
  }
  case 3: {
    int newViews;
    std::cout << "Введите новое число просмотров\n";
    std::cin >> newViews;
    Article::editObjViews(list, size, objName, newViews);
    break;
  }
  case 4: {
    int newLikes;
    std::cout << "Введите новое число лайков\n";
    std::cin >> newLikes;
    Article::editObjLikes(list, size, objName, newLikes);
    break;
  }
  default: {
    std::cout << "Тип действия выбран некорректно\n";
    break;
  }
  }
}

void StartSolarSystem() {
  int size = 0;
  const char fileName[] = "SolarSystem.txt";
  Planet* list = nullptr;
  char objName[30];
  Planet obj;

  char continueExecution = 'y';
  while (continueExecution == 'y') {
    std::cout << "Выберете действиe и введите соответствующую цифру: \n";
    std::cout << "1 - Прочитать список планет из файла\n";
    std::cout << "2 - Записать список планет в файл\n";
    std::cout << "3 - Отсортировать список планет\n";
    std::cout << "4 - Добавить планету в список\n";
    std::cout << "5 - Удалить планету из списка\n";
    std::cout << "6 - Редактировать планету из списка\n";
    std::cout << "7 - Вывести список планет\n";

    int action = 0;
    std::cin >> action;

    switch (action) {
    case 1: {
      Planet::readFromFile(list, size, fileName);
      break;
    }
    case 2: {
      Planet::writeToFile(list, size, fileName);
      break;
    }
    case 3: {
      Planet::sortList(list, size);
      break;
    }
    case 4: {
      std::cout << "Введите параметры планеты через пробел: имя, диаметр, "
                   "население, число спутников\n";
      std::cin >> obj;
      Planet::pushObj(list, size, obj);
      std::cout << "Планета добавлена\n";
      break;
    }
    case 5: {
      std::cout << "Введите имя планеты, которую хотите удалить\n";
      std::cin >> objName;
      Planet::deleteObj(list, size, objName);
      break;
    }
    case 6: {
      std::cout << "Введите имя планеты, которую хотите редактировать\n";
      std::cin >> objName;
      ChoseEditPlanetPlace(list, size, objName);
      break;
    }
    case 7: {
      Planet::printList(list, size);
      break;
    }
    default: {
      std::cout << "Тип действия выбран некорректно\n";
      break;
    }
    }
    std::cout << "Продолжить работу с этим классом? (y/n)\n";
    std::cin >> continueExecution;
  }
}

void StartArticle() {
  int size = 0;
  const char fileName[] = "ArticleList.txt";
  Article* list = nullptr;
  char objName[30];
  Article obj;

  char continueExecution = 'y';
  while (continueExecution == 'y') {
    std::cout << "Выберете действиe и введите соответствующую цифру: \n";
    std::cout << "1 - Прочитать список статей из файла\n";
    std::cout << "2 - Записать список статей в файл\n";
    std::cout << "3 - Отсортировать список статей по популярности\n";
    std::cout << "4 - Добавить статью в список\n";
    std::cout << "5 - Удалить статью из списка\n";
    std::cout << "6 - Редактировать статью из списка\n";
    std::cout << "7 - Вывести список статей\n";

    int action = 0;
    std::cin >> action;

    switch (action) {
    case 1: {
      Article::readFromFile(list, size, fileName);
      break;
    }
    case 2: {
      Article::writeToFile(list, size, fileName);
      break;
    }
    case 3: {
      Article::sortList(list, size);
      break;
    }
    case 4: {
      std::cout << "Введите параметры статьи через пробел: имя, номер, "
                   "число просмотров, число лайков\n";
      std::cin >> obj;
      Article::pushObj(list, size, obj);
      std::cout << "Статья добавлена\n";
      break;
    }
    case 5: {
      std::cout << "Введите имя статьи, которую хотите удалить\n";
      std::cin >> objName;
      Article::deleteObj(list, size, objName);
      break;
    }
    case 6: {
      std::cout << "Введите имя статьи, которую хотите редактировать\n";
      std::cin >> objName;
      ChoseEditArticlePlace(list, size, objName);
      break;
    }
    case 7: {
      Article::printList(list, size);
      break;
    }
    default: {
      std::cout << "Тип действия выбран некорректно\n";
      break;
    }
    }
    std::cout << "Продолжить работу с этим классом? (y/n)\n";
    std::cin >> continueExecution;
  }
}

void StartApp() {
  char continueExecution = 'y';
  while (continueExecution == 'y') {
    std::cout << "Выберете класс:\n";
    std::cout << "Солнечная система - 1\n";
    std::cout << "Статья в журнале - 2\n";

    int classType = 0;
    std::cin >> classType;

    switch (classType) {
    case 1: {
      StartSolarSystem();
      break;
    }
    case 2: {
      StartArticle();
      break;
    }
    default: {
      std::cout << "\n";
      break;
    }
    }

    std::cout << "Продолжить работу? (y/n)\n";
    std::cin >> continueExecution;
  }
}
} // namespace Application