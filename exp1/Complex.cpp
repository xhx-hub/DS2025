#include "Complex.h"

// 构造函数实现
Complex::Complex(double r, double i) : real(r), imag(i) {}

// 析构函数实现（无动态资源，为空函数）
Complex::~Complex() {}

// 获取实部
double Complex::getReal() const {
    return real;
}

// 获取虚部
double Complex::getImag() const {
    return imag;
}

// 设置实部
void Complex::setReal(double r) {
    real = r;
}

// 设置虚部
void Complex::setImag(double i) {
    imag = i;
}

// 复数加法运算符重载
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

// 复数减法运算符重载
Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

// 复数乘法运算符重载
Complex Complex::operator*(const Complex& other) const {
    // (a+bi)*(c+di) = (ac - bd) + (ad + bc)i
    double newReal = real * other.real - imag * other.imag;
    double newImag = real * other.imag + imag * other.real;
    return Complex(newReal, newImag);
}

// 打印复数
void Complex::print() const {
    if (imag >= 0) {
        printf("%.2f + %.2fi\n", real, imag);
    } else {
        printf("%.2f - %.2fi\n", real, -imag);
    }
}
