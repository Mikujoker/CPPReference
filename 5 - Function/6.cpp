#include<iostream>
using namespace std;

int fib()
{
    static int a = 0, b = 1;
    int c = a + b;
    a = b; // 更新为下一个数字
    b = c; // 更新为下一个数字
    return a; // 返回当前计算出的斐波那契数
}


int main()
{
    int i;
    for(i = 0; i < 10; i++)
        cout << fib() << endl;
	return 0;
}
