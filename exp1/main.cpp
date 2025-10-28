#include "Complex.h"
#include "StackCalc.h"
#include "MaxArea.h"
#include <vector>
#include <iostream>

int main() {
    // 测试复数类
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 + c2;
    std::cout << "复数加法测试：";
    c3.print();

    // 测试栈计算器
    StackCalc calc;
    std::string expr = "3+4*2/(1-5)";
    double result = calc.evaluate(expr);
    std::cout << "栈计算器测试：" << expr << " = " << result << std::endl;

    // 测试柱状图最大面积
    MaxArea ma;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int maxArea = ma.largestRectangleArea(heights);
    std::cout << "柱状图最大面积测试：" << maxArea << std::endl;

    return 0;
}
