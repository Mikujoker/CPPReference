#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include<string>

struct Calculator
{
private:
    char* self_expression;
    char* total_expression;
    int value;
public:
    Calculator(const char* expr);
    ~Calculator();
    Calculator & combine(const Calculator & sa);
    void print_value() const;
    void print_total_expression() const;
    void print_self_expression() const;
};

#endif // CLASS_H