#pragma once

class Cmplx {
    double re;
    double im;

   public:
    Cmplx(double real, double imag);

    void read();

    void add(Cmplx x);

    double abs() const;

    void print() const;
};