#include <iostream>
#include <sstream> // 引入 ostringstream
#include <iomanip> // 用于输出时保持格式

using namespace std;

struct complex_number {
    int real;
    int imag;

    // 构造函数
    complex_number(int r = 0, int i = 0) : real(r), imag(i) {}

    // 返回两个复数的和
    complex_number complex_add(complex_number b) const {
        return complex_number(real + b.real, imag + b.imag);
    }

    // 返回两个复数的乘积
    complex_number complex_mul(complex_number b) const {
        return complex_number(real * b.real - imag * b.imag, imag * b.real + real * b.imag);
    }

    // 返回复数的字符串表示
    string Show() const {
        ostringstream oss;
        if(imag > 0){
            oss << real << "+" << imag << "i";
        }
        else if(imag < 0){
            oss << real << imag << "i";

        }
        else{
            oss << real;
        }
        return oss.str();
    }
};

int main() {
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    complex_number x(a, b), y(c, d), sum, product;

    cout << "x = " << x.Show() << endl;
    cout << "y = " << y.Show() << endl;
    sum = x.complex_add(y);
    cout << "x += y; x = " << sum.Show() << endl;
    product = sum.complex_mul(y);
    cout << "y *= x; y = " << product.Show() << endl;
    x = sum.complex_add(product); // 更新x为x+y的结果
    cout << "x + y = " << x.Show() << endl;
    y = sum.complex_mul(product); // 更新y为y*x的结果
    cout << "y * x = " << y.Show() << endl;
    cout << "x = " << sum.Show() << endl;
    cout << "y = " << product.Show() << endl;

    return 0;
}
