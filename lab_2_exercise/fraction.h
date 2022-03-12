#pragma once
#include <cstdlib>
#include <iostream>
using namespace std;

class Fraction {
    int nominator;
    int denominator;

   public:
    Fraction(int nominator = 0, int denominator = 1);
    void read();
    void write() const;
    void shorten();

    friend Fraction add(const Fraction& a, const Fraction& b);
};

int gcd(int a, int b);

// ostream& operator<<(ostream& out, Fraction u);
// istream& operator>>(istream& in, Fraction& u);