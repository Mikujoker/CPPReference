#include<iostream>
#include <stdio.h> 
using namespace std;
int main() 
{

    // 请在此添加代码
    /********** Begin *********/
    int num1,num2,num3,num4;
    cin >> num1;

    num2 = num1 / 100 ;
    num3 = (num1/10)%10 ;
    num4 =  num1%10;

    cout << num1 << "的百位数字是" << num2 << "，十位数字是" << num3 <<"，个位数字是" << num4;



    /********** End **********/




  return 0;
}


