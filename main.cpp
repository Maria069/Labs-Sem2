#include "MyContainers/MySet.h"
#include <iostream>

int main() {
    std::cout << "Демонстрация работы с вектором:\n";

    MyVector<char*> v;
    std::cout << v;
    v.add_element("xw");
    v.add_element("ss");
    v.add_element("ab");
    v.add_element("cd");
    v.add_element("bc");
    std::cout << v;
    MyVector<char*> v2(v);
    std::cout << v2;
    v.delete_element(1);
    std::cout << "v = " << v << "v2 = " << v2;
    v.sort();
    std::cout << "v = " << v << "v2 = " << v2;

    std::cout << "Демонстрация работы с множеством:\n";

    MySet<char*> s;
    s.add_element("mn");
    s.add_element("df");
    s.add_element("ab");
    s.add_element("df");
    s.add_element("ab");
    s.add_element("kl");
    MySet<char*> s1 = s;
    s1.add_element("op");
    s1.add_element("xy");
    s1.delete_element("df");
    std::cout << "s = " << s << "s1 = " << s1;
    std::cout << "s - s1 = " << s - s1;
    std::cout << "s1 - s = " << s1 - s;
    std::cout << "s + s1 = " << s + s1;
    std::cout << "s * s1 = " << s * s1;
    return 0;
}