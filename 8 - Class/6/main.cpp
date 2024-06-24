#include <iostream>
#include "class.h"

using namespace std;

int main() {
    
    double x1, y1, x2, y2;

    cin >> x1 >> y1;
    cin >> x2 >> y2;

    // 创建复数对象
    Complex c1(x1, y1);
    Complex c2(x2, y2);

    // 计算并输出结果
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;
    Complex quot = c1 / c2;

    cout << sum << endl;
    cout << diff << endl;
    cout << prod << endl;
    cout << quot << endl;

    return 0;
}
