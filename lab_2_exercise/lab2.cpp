#include <iostream>

#include "fraction.h"

int main() {
    std::cout << "dupa";
    Fraction u1, u2;

    u1.read();
    std::cout << "u1= ";
    u1.write();

    u2.read();
    std::cout << "u2= ";
    u2.write();

    std::cout << endl << "Addition of two fractions:" << std::endl;
    Fraction u3 = add(u1, u2);
    std::cout << endl << "u3=u1+u2= ";
    u3.write();

    std::cout << endl << "u2+u2= ";
    add(u2, u2).write();

    // cin >> u1 >> u2;
    // cout << u1 << u2 << endl;

    // Fraction u4(8, -10);
    // cout << u4;

    std::cout << endl;
}