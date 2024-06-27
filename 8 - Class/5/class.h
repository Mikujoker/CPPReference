#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class BigInteger {
private:
    int* digits; // 动态数组存储每一位数字
    int length;  // 数字的总位数

public:
    static const int MAX_DIGITS = 1000;

    // 构造函数
    BigInteger();
    BigInteger(const std::string &num);
    BigInteger(const BigInteger &other); // 拷贝构造函数
    ~BigInteger(); // 析构函数

    // 成员函数
    void read();

    // 友元函数
    friend BigInteger add(const BigInteger &a, const BigInteger &b);

    // 重载输出运算符
    friend ostream& operator<<(std::ostream &out, const BigInteger &num);

    // 重载赋值运算符
    BigInteger& operator=(const BigInteger &other);
};

#endif // CLASS_H
