#include "cmplx.h"

#include <cmath>
#include <cstdlib>
#include <iostream>

Cmplx::Cmplx(double real, double imag) {
    re = real;
    im = imag;
}

void Cmplx::read() {
    std::cout << "Insert Re:";
    std::cin >> re;
    std::cout << "Insert Im:";
    std::cin >> im;
}

void Cmplx::add(Cmplx x) {
    re += x.re;
    im += x.im;
}

double Cmplx::abs() const { return sqrt(re * re + im * im); }

void Cmplx::print() const { std::cout << re << "+" << im << 'i' << std::endl; }
