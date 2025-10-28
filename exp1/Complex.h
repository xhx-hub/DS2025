#ifndef COMPLEX_H
#define COMPLEX_H

class Complex {
private:
    double real;   // 实部
    double imag;   // 虚部
public:
    // 构造函数
    Complex(double r = 0.0, double i = 0.0);
    // 析构函数
    ~Complex();
    // 成员函数：获取实部和虚部
    double getReal() const;
    double getImag() const;
    // 成员函数：设置实部和虚部
    void setReal(double r);
    void setImag(double i);
    // 运算符重载：复数加法
    Complex operator+(const Complex& other) const;
    // 运算符重载：复数减法
    Complex operator-(const Complex& other) const;
    // 运算符重载：复数乘法
    Complex operator*(const Complex& other) const;
    // 打印复数
    void print() const;
};

#endif // COMPLEX_H
