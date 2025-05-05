#include "MyStack/MyStack.h"
#include <iostream>

template<typename DATA>
void Multipliers(int n, MyStack<DATA> &stack) {
    int div = 2;
    while (div * div <= n) {
        while (n % div == 0) {
            n /= div;
            stack.push(div);
        }
        div++;
    }
    if (n > 1) {
        stack.push(n);
    }
}

int main() {
    int n;
    std::cin >> n;

    MyStack<int> dividers;
    MyStack<int> dividersReverce;
    Multipliers(n, dividers);

    std::cout << dividers[0] << ' ' << dividers[2] << ' ' <<  dividers[5] << '\n';

    MyStack<int> forCopy;
    forCopy = dividers;
    std::cout << forCopy.inf() << '\n';

    std::cout << "Все простые делители по возрастанию:\n";
    std::cout << n << " = ";
    while (!dividers.empty()) {
        int tmp = dividers.inf();
        dividersReverce.push(tmp);
        dividers.pop();
        std::cout << tmp;
        if (!dividers.empty()) {
            std::cout << " * ";
        }
    }
    std::cout << '\n';
    std::cout << "Все простые делители по убыванию:\n";
    std::cout << n << " = ";
    while (!dividersReverce.empty()) {
        int tmp = dividersReverce.inf();
        dividersReverce.pop();
        std::cout << tmp;
        if (!dividersReverce.empty()) {
            std::cout << " * ";
        }
    }
    std::cout << '\n';
    return 0;
}