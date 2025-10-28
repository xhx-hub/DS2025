#include "StackCalc.h"
#include <stdexcept>
#include <iostream>

bool StackCalc::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int StackCalc::getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double StackCalc::calculate(double a, double b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) throw std::runtime_error("Division by zero");
            return a / b;
        default: return 0;
    }
}

double StackCalc::evaluate(const std::string& expression) {
    std::string exp = expression;
    size_t i = 0;
    while (i < exp.length()) {
        if (std::isdigit(exp[i]) || exp[i] == '.') { // 数字或小数点
            std::string numStr;
            while (i < exp.length() && (std::isdigit(exp[i]) || exp[i] == '.')) {
                numStr += exp[i++];
            }
            numStack.push(std::stod(numStr));
        } else if (isOperator(exp[i])) { // 运算符
            while (!opStack.empty() && getPriority(opStack.top()) >= getPriority(exp[i])) {
                double b = numStack.top(); numStack.pop();
                double a = numStack.top(); numStack.pop();
                char op = opStack.top(); opStack.pop();
                numStack.push(calculate(a, b, op));
            }
            opStack.push(exp[i++]);
        } else if (exp[i] == '(') { // 左括号
            opStack.push(exp[i++]);
        } else if (exp[i] == ')') { // 右括号
            while (!opStack.empty() && opStack.top() != '(') {
                double b = numStack.top(); numStack.pop();
                double a = numStack.top(); numStack.pop();
                char op = opStack.top(); opStack.pop();
                numStack.push(calculate(a, b, op));
            }
            if (!opStack.empty() && opStack.top() == '(') {
                opStack.pop();
            }
            i++;
        } else { // 跳过空格
            i++;
        }
    }

    while (!opStack.empty()) {
        double b = numStack.top(); numStack.pop();
        double a = numStack.top(); numStack.pop();
        char op = opStack.top(); opStack.pop();
        numStack.push(calculate(a, b, op));
    }

    if (numStack.size() != 1) {
        throw std::runtime_error("Invalid expression");
    }
    return numStack.top();
}
