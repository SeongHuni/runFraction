#include "runFraction.h"
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    // 음수 입력에 대한 처리
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 기본 생성자
Fraction::Fraction() : numerator(1), denominator(1) {}

// 매개변수 있는 생성자
Fraction::Fraction(int num, int den) {
    set(num, den);
}

// set 메서드: 분수 값 설정 및 예외 처리
void Fraction::set(int num, int den) {
    if (den == 0) {
        cout << "ERR" << endl;
        this->numerator = num;
        this->denominator = 1;
    }
    else {
        this->numerator = num;
        this->denominator = den;
    }
    simplify();
}

// 분수를 약분하고 음수 부호를 정리하는 도우미 함수
void Fraction::simplify() {
    if (denominator == 0) return;

    // 분모가 음수일 경우 부호를 정리
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }

    // 최대공약수를 이용해 약분
    int common = gcd(numerator, denominator);
    numerator /= common;
    denominator /= common;
}

// 분수 덧셈
Fraction Fraction::add(const Fraction& other) const {
    int newNum = this->numerator * other.denominator + other.numerator * this->denominator;
    int newDen = this->denominator * other.denominator;
    return Fraction(newNum, newDen);
}

// 분수 출력
void Fraction::print() const {
    if (denominator == 1) {
        cout << numerator << endl;
    }
    else {
        cout << numerator << "/" << denominator << endl;
    }
}