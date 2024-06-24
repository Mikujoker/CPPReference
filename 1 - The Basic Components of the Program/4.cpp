#include<iostream>
#include <stdio.h> 
using namespace std;
int main() 
{

    // 请在此添加代码
    /********** Begin *********/
    int num , a , b , c ,d;
    cin >> num;

    a = num / 1000 + 13;
    b = num / 100 % 10 + 13;
    c = num / 10 % 10 + 13;
    d = num % 10 +13;

    char charA = 'A' + a - 1; // 转换为对应的大写字母
    char charB = static_cast<char>('A' + b - 1);
    char charC = static_cast<char>('A' + c - 1);
    char charD = static_cast<char>('A' + d - 1);

    cout <<  charA << charB << charC << charD << endl;



    /********** End **********/




  return 0;
}


