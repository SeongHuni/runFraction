#pragma once

class Fraction {
public:
    Fraction();
    Fraction(int num, int den);
    void set(int num, int den);
    Fraction add(const Fraction& other) const;
    void print() const;

private:
    int numerator;   // 분자
    int denominator; // 분모

    void simplify();
};