#include "MyClasses/MyPolynomial.h"


int main(int, char**) {
    MyTerm a(2, 3);
    MyTerm b(-4, 5);
    

    MyPolynomial p;
    MyPolynomial p1;
    std::cin >> p;
    std::cout << p;

    std::cin >> p1;
    std::cout << p1;

    std::cout << p + p1;
    std::cout << p * p1;
    
    return 0;
}