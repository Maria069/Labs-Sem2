#include <iostream>
#include "mymath/mymath.h"

int main(int, char**) {
    std::cout << "НОД 10 и 22 = ";
    std::cout << mymath::NOD(10, 22) << std::endl;

    return 0;
}
