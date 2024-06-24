#ifndef CLASS_H
#define CLASS_H

#include <iostream>

using namespace std;

class Complex{

public:
    
    Complex(double real = 0.0, double imag = 0.0);

    Complex operator+(const Complex& other) const;

    Complex operator-(const Complex& other) const;

    Complex operator*(const Complex& other) const;

    Complex operator/(const Complex& other) const;

    friend ostream& operator<<(ostream& out, const Complex& c);

private:

    double real;

    double imag;

};


#endif /* CLASS_H */