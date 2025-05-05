#include "Application.h"
#include "MyClasses/complex.h"
#include "MyClasses/rectangle.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <random>
#include <algorithm>

namespace {
void printVector(std::vector<int> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
}

void getDoubleVector(std::vector<int> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = v[i] * 2;
    }
}

void fillRandomVector(std::vector<int> &v) {
    std::random_device generator{};
    std::default_random_engine randomEngine(generator());
    std::uniform_int_distribution distribution(0, 100);

    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = distribution(randomEngine);
    }
}

//template<typename DATA>
void printList(std::list<int> &l) {
    std::list<int>::iterator iter;
    for (iter = l.begin(); iter != l.end(); ++iter) {
        std::cout << *iter << ' ';
    }
    std::cout << '\n';
}

void printList(std::list<Rectangle> &l) {
    std::list<Rectangle>::iterator iter;
    for (iter = l.begin(); iter != l.end(); ++iter) {
        std::cout << *iter;
    }
    std::cout << '\n';
}

void getDoubleList(std::list<int> &l) {
    std::list<int>::iterator iter;
    std::list<int> l1;
    for (iter = l.begin(); iter != l.end(); ++iter) {
        l1.push_back(*iter * 2);
    }
    l = l1;
}

void fillRandomList(std::list<int> &l) {
    std::random_device generator{};
    std::default_random_engine randomEngine(generator());
    std::uniform_int_distribution distribution(0, 100);

    std::list<int>::iterator iter;
    std::list<int> l1;
    for (iter = l.begin(); iter != l.end(); ++iter) {
        l1.push_back(distribution(randomEngine));
    }
    l = l1;
}

void printMap(std::map<std::string, int> &m) {
  std::map<std::string, int>::iterator i;
    for (i = m.begin(); i != m.end(); ++i) {
        std::cout << i->first << ' ' << i->second << '\n';
    }
}

void printMap(std::map<std::string, std::string> &m) {
  std::map<std::string, std::string>::iterator i;
    for (i = m.begin(); i != m.end(); ++i) {
        std::cout << i->first << ' ' << i->second << '\n';
    }
}
} //namespace

namespace Application {
void ExecuteTackOne() {
    std::cout << "Введите текст:\n";

    std::string s;
    getline(std::cin, s);

    int cnt = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '@') {
            cnt++;
        }
    }

    std::cout << "Кол-во символов @ в данном тексте: " << cnt << '\n';
}

void ExecuteTackTwo() {
    std::cout << "Введите фамилию, имя, отчество через пробел:\n";

    std::string surname = "";
    std::string name = "";
    std::string fatherName = "";
    std::cin >> surname >> name >> fatherName;

    if (name == "" || surname == "" || fatherName == "") {
        std::cout << "Данные введены некорректно\n";
        return;
    }

    std::cout << surname << " " << name[0] << ". " << fatherName[0] << ".\n";
}

void ExecuteTackThree() {
    std::fstream start("startFile.txt");
    std::fstream final("finalFile.txt");
    
    if (!start || !final) {
        std::cout << "Файлы не открылись\n";
        return;
    }

    std::string s;
    while(!start.eof()) {
        getline(start, s);
        final << '-' << s << '\n';
    }
    std::cout << "Записали содержимое одного файла в другой, добавив символ - к каждой строке\n";

    start.close();
    final.close();
}

void ExecuteTackFour() {
    std::vector<int> v(5);
    fillRandomVector(v);
    printVector(v);

    getDoubleVector(v);
    printVector(v);

    v.erase(v.begin()+2);
    printVector(v);
}

void ExecuteTackFive() {
    std::vector<Complex> v = {Complex(-1.2, 6.3), Complex(4.0, 0.7), Complex(7.2, -0.8), Complex(5.3, 3.0), Complex(-4.9, 6.6), Complex(-9.3, 0.2)};

    std::cout << "Вектор комплексных чисел:\n";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
    }

    //alg
    Complex sum = std::accumulate(v.begin(), v.end(), Complex(0, 0));
    std::cout << "Сумма чисел в векторе:\n";
    std::cout << sum; 
}

void ExecuteTackSix() {
    std::list<int> l(6);
    fillRandomList(l);
    printList(l);

    getDoubleList(l);
    printList(l);

    //next
    auto it = l.begin();
    it = std::next(it, 2);
    l.erase(it);
    printList(l);
}

void ExecuteTackSeven() {
    std::list<Rectangle> l = {Rectangle(1.2, 6.3), Rectangle(4.0, 0.7), Rectangle(7.2, 0.8), Rectangle(5.3, 3.0), Rectangle(4.9, 6.6), Rectangle(9.3, 0.2)};
    printList(l);

    Rectangle mx = *std::max_element(l.begin(), l.end());
    std::cout << '\n'; //max_element
    std::cout << "Самый большой прямоугольник:\n";
    std::cout << mx;
}

void ExecuteTackEight() {
    std::map<std::string, int> m;
    m["one"] = 100;
    m["two"] = 200;
    m["three"] = 300;
    m["four"] = 400;
    m["five"] = 500;
    m["six"] = 600;
    printMap(m);

    m.erase("five");
    m.erase("six");
    std::cout << "Мапа после удаления элементов:\n";
    printMap(m);
}

void ExecuteTackNine() {
    std::map<std::string, std::string> m;
    int n;
    std::string s1, s2;

    std::cout << "Введите кол-во абонентов, затем в отдельных строках абонента и номер через пробел\n";
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> s1 >> s2;
        m[s1] = s2;
    }

    std::cout << "Список номеров:\n";
    printMap(m);

    std::cout << "Введите имя абонента\n";
    std::cin >> s1;
    std::cout << "Номер данного абонента:\n";
    std::cout << m[s1] << '\n';

    m.erase(s1);
    std::cout << "Список номеров без данного номера:\n";
    printMap(m);
}

void SelectTask(int task) {
  switch (task) {
  case 1: {
    ExecuteTackOne();
    break;
  }
  case 2: {
    ExecuteTackTwo();
    break;
  }
  case 3: {
    ExecuteTackThree();
    break;
  }
  case 4: {
    ExecuteTackFour();
    break;
  }
  case 5: {
    ExecuteTackFive();
    break;
  }
  case 6: {
    ExecuteTackSix();
    break;
  }
  case 7: {
    ExecuteTackSeven();
    break;
  }
  case 8: {
    ExecuteTackEight();
    break;
  }
  case 9: {
    ExecuteTackNine();
    break;
  }
  default: {
    std::cout << "Номер задания введен некорректно\n";
    break;
  }
  }
}

void StartApp() {
  char continueExecution = 'y';
  while (continueExecution == 'y') {
    std::cout << "Выберете номер задания от 1 до 9 включительно\n";

    int task = 0;
    std::cin >> task;

    std::string s;
    getline(std::cin, s);

    SelectTask(task);

    std::cout << "Продолжить работу? (y/n)\n";
    std::cin >> continueExecution;
  }
}
} // namespace Application