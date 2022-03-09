#include <cstdlib>
#include <iostream>

#include "cmplx.h"

int main() {
    Cmplx number1 = Cmplx(3, 4), number2 = Cmplx(3, 7);

    number1.add(number2);
    number1.print();
    std::cout << "Hello world!";

    return 1;
}