#include "class.h"
#include <cstring>
#include <iostream>
#include <string>

using namespace std;


Calculator::Calculator(const char* expr) {
    
    self_expression = new char[strlen(expr) + 1];
    strcpy(self_expression, expr);

    
    total_expression = new char[strlen(expr) + 1];
    strcpy(total_expression, expr);

    // 解析表达式并计算初始值
    string expr_str(expr);
    if (expr[0] == '+') {
        value = stoi(expr_str.substr(1));
    } else if (expr[0] == '-') {
        value = -stoi(expr_str.substr(1));
    } else {
        value = 0;
    }
}


Calculator::~Calculator() {
    delete[] self_expression;
    delete[] total_expression;
}


void Calculator::print_value() const {
    cout << "value is " << value << endl;
}


void Calculator::print_total_expression() const {
    cout << total_expression << endl;
}


void Calculator::print_self_expression() const {
    cout << self_expression << endl;
}

// 合并表达式并更新值
Calculator & Calculator::combine(const Calculator & sa) {
    // 计算新的总表达式长度并分配内存
    size_t new_length = strlen(total_expression) + strlen(sa.total_expression) + 1;
    char* new_total_expression = new char[new_length];
    
    // 组合表达式
    strcpy(new_total_expression, total_expression);
    strcat(new_total_expression, sa.total_expression);

    // 更新 total_expression
    delete[] total_expression;
    total_expression = new_total_expression;

    // 更新值
    value += sa.value;

    return *this;
}
