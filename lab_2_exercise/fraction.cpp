#include "fraction.h"

#include <cstdlib>
#include <iostream>

Fraction::Fraction(int nominator, int denominator) {
    this->nominator = nominator;
    this->denominator = denominator;
    shorten();
}

void Fraction::read() {
    std::cin >> nominator >> denominator;
    shorten();
}

void Fraction::write() const {
    cout << nominator << "/" << denominator << std::endl;
}

void Fraction::shorten() {
    int divider = gcd(nominator, denominator);
    nominator /= divider;
    denominator /= divider;
}

Fraction add(const Fraction& a, const Fraction& b) {
    Fraction f(a.nominator * b.denominator + b.nominator * a.denominator,
               a.denominator * b.denominator);
    return f;
}

int gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}