#ifndef STACKCALC_H
#define STACKCALC_H

#include <string>
#include <stack>
#include <cctype>

class StackCalc {
private:
    std::stack<double> numStack;   // 存储数字的栈
    std::stack<char> opStack;      // 存储运算符的栈

    // 判断是否为运算符
    bool isOperator(char c);
    // 获取运算符优先级
    int getPriority(char op);
    // 执行一次运算
    double calculate(double a, double b, char op);

public:
    // 计算表达式的值
    double evaluate(const std::string& expression);
};

#endif // STACKCALC_H
