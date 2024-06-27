# 复习笔记

## 1.时钟显示
```cpp
void showTime() const {
        cout << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << endl;
}
```

## 2.矩阵
>编写一个简单的矩阵类Matrix，能实现mxn阶矩阵的初始化(Initialization)、转置(Transpose)并打印、以及方阵行列式(Determinant)的计算。依次输出转置矩阵，和行列式，如果没有行列式，输出字符@
```cpp
//class.cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include "class.h"
using namespace std;

Matrix::Matrix(int rows, int cols) {
    matrix.resize(rows);
    for (int i = 0; i < rows; ++i) {
        matrix[i].resize(cols);
    }
}

void Matrix::inputMatrix() {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cin >> matrix[i][j];
        }
    }
}

void Matrix::transpose() {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposedMatrix(cols, vector<int>(rows));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    matrix = move(transposedMatrix);
}

int Matrix::determinant() {
    int rows = matrix.size();
    int cols = matrix[0].size();
    if (rows != cols) {
        return -1;
    }
    if (rows == 1) {
        return matrix[0][0];
    }
    int det = 0;
    for (int i = 0; i < rows; ++i) {
        Matrix subMatrix(rows - 1, cols - 1);
        for (int j = 1; j < rows; ++j) {
            for (int k = 0; k < cols; ++k) {
                if (k < i) {
                    subMatrix.matrix[j - 1][k] = matrix[j][k];
                } else if (k > i) {
                    subMatrix.matrix[j - 1][k - 1] = matrix[j][k];
                }
            }
        }
        det += ((i % 2 == 0) ? 1 : -1) * matrix[0][i] * subMatrix.determinant();
    }
    return det % 1000000007;
}
```
```cpp
//class.h

#ifndef CLASS_H
#define CLASS_H

#include <vector>

using namespace std;

class Matrix {
public:
    vector<vector<int>> matrix;

    Matrix(int rows, int cols);
    void inputMatrix();
    void transpose();
    int determinant();
};

#endif
```
```cpp
//main.cpp
#include <iostream>
#include "class.h"

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;
    Matrix matrix(rows, cols);
    matrix.inputMatrix();
    matrix.transpose();
    int det = matrix.determinant();
    
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout << matrix.matrix[i][j];
            if (j != rows - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    if (det == -1)  cout << "@" << endl;
    else    cout << det;
    
    return 0;
}
```

## 3.大整数类
>要求实现BigInteger类  即能存储任意位数(不超过1000位)的非负整数
以私有成员形式存储非负数(int数组)本身和总位数
以成员函数形式从cin读入数据
以友元函数形式实现两个正数的加法，返回一个非负数(也是BigInteger对象)(不超过1000位)

```cpp
//class.cpp
#include "class.h"
#include <cstring>

using namespace std;

BigInteger::BigInteger() : length(0) {
    digits = new int[MAX_DIGITS];
    for (int i = 0; i < MAX_DIGITS; ++i) {
        digits[i] = 0;
    }
}

BigInteger::BigInteger(const string &num) {
    length = num.size();
    digits = new int[MAX_DIGITS];
    for (int i = 0; i < MAX_DIGITS; ++i) {
        digits[i] = 0;
    }
    for (int i = 0; i < length; ++i) {
        digits[i] = num[length - 1 - i] - '0';
    }
}

BigInteger::BigInteger(const BigInteger &other) {
    length = other.length;
    digits = new int[MAX_DIGITS];
    for (int i = 0; i < MAX_DIGITS; ++i) {
        digits[i] = other.digits[i];
    }
}

BigInteger::~BigInteger() {
    delete[] digits;
}

void BigInteger::read() {
    string num;
    cin >> num;
    *this = BigInteger(num);
}

BigInteger add(const BigInteger &a, const BigInteger &b) {
    BigInteger result;
    int maxLength = max(a.length, b.length);
    int carry = 0;

    for (int i = 0; i < maxLength; ++i) {
        int digitA = (i < a.length) ? a.digits[i] : 0;
        int digitB = (i < b.length) ? b.digits[i] : 0;

        int sum = digitA + digitB + carry;
        result.digits[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) {
        result.digits[maxLength] = carry;
        result.length = maxLength + 1;
    } else {
        result.length = maxLength;
    }

    return result;
}

ostream& operator<<(std::ostream &out, const BigInteger &num) {
    for (int i = num.length - 1; i >= 0; --i) {
        out << num.digits[i];
    }
    return out;
}

BigInteger& BigInteger::operator=(const BigInteger &other) {
    if (this == &other) {
        return *this;
    }

    delete[] digits;

    length = other.length;
    digits = new int[MAX_DIGITS];
    for (int i = 0; i < MAX_DIGITS; ++i) {
        digits[i] = other.digits[i];
    }

    return *this;
}
```
```cpp
//class.h
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
```
```cpp
//main.cpp
#include <iostream>
#include "class.h"


using namespace std;

int main(){
    BigInteger num1, num2;
    num1.read();
    num2.read();

    BigInteger sum = add(num1, num2);

    cout << sum;

    return 0;



    return 0;
}
```

## 4.典中典罗马数字
>编写一个罗马数字与整数的类RomanWithInt，类中函数能实现罗马数字与整数的相互转化

```cpp
//class.cpp
#include "class.h"

using namespace std;

RomanWithInt::RomanWithInt() {}

int RomanWithInt::getValue(char ch) const {
    switch (ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int RomanWithInt::romanToInt(const string& s) const {
    int total = 0;
    int prevValue = 0;
    
    for (int i = s.size() - 1; i >= 0; --i) {
        int value = getValue(s[i]);
        if (value < prevValue) {
            total -= value;
        } else {
            total += value;
        }
        prevValue = value;
    }
    
    return total;
}

string RomanWithInt::intToRoman(int num) const {
    const pair<int, string> valueSymbols[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    
    string result;
    for (const auto& pair : valueSymbols) {
        while (num >= pair.first) {
            result += pair.second;
            num -= pair.first;
        }
    }
    
    return result;
}
```
```cpp
//class.h
#ifndef CLASS_H
#define CLASS_H

#include <string>

using namespace std;

class RomanWithInt {
public:

    RomanWithInt();

    int romanToInt(const string& s) const;

    string intToRoman(int num) const;

private:

    int getValue(char ch) const;
};

#endif // CLASS_H
```
```cpp
//main.cpp
#include <iostream>
#include "class.h"

using namespace std;

int main() {
    RomanWithInt converter;
    string input;
    
    while (cin >> input && input != "@") {
        if (isdigit(input[0])) {
            int num = stoi(input);
            cout << converter.intToRoman(num) << endl;
        } else {
            cout << converter.romanToInt(input) << endl;
        }
    }
    
    return 0;
}
```
## 6.典中典之链表
```cpp
#include <iostream>

using namespace std;

struct linkRec
{
    int data;
    linkRec *next;
};

// 插入节点函数
void insertNode(linkRec* p, int x) {
    linkRec *newNode = new linkRec;
    newNode->data = x;
    newNode->next = p->next;
    p->next = newNode;
}

// 删除节点函数
void deleteNode(linkRec* p) {
    linkRec *delptr = p->next;
    p->next = delptr->next;
    delete delptr;
}

// 创建链表函数
linkRec* createList() {
    int x;
    linkRec *head, *p, *rear;
    head = rear = new linkRec;

    while(true){
        cin >> x;
        if (x == 0) break;
        p = new linkRec;
        p->data = x;
        rear -> next = p;
        rear = p;
    }
    rear ->next = NULL;

    return head;
}

// 打印链表函数
void printList(linkRec* head) {
    cout << "The list is: \n";
    
    linkRec* p = head -> next;
    while (p != NULL){
        cout << p -> data << "\t";
        p = p -> next;
    }
    cout << endl;
}

int main(){
    linkRec* head = createList();
    printList(head);

    return 0;   
}
```