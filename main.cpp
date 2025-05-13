#include "MyContainers/MyVector.h"
#include <iostream>

int main() {
    MyVector<int> v;
    MyVector<int> v1(5);
    std::cout << v << v1;
    v.add_element(5);
    v.add_element(4);
    v.add_element(1);
    v.add_element(3);
    v.add_element(2);
    std::cout << v << '\n';
    MyVector<int> v2(v);
    std::cout << v2 << '\n';
    v.delete_element(1);
    std::cout << v << v2;
    v.sort();
    std::cout << v << v2;
    return 0;
}