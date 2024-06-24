#include<iostream>
#include <stdio.h> 
#include <iomanip>
using namespace std;
int main() 
{

    // 请在此添加代码
    /********** Begin *********/
    int num1,num2,num3,num4;
    cin >> num1 >> num2 >> num3 >> num4;

    double average;
    average = (num1 + num2 + num3 + num4) / 4.0;

    cout << num1 << "、" << num2 << "、" << num3 << "、" << num4 << "的平均值是" << std::fixed << std::setprecision(2) << average << std::endl;


    /********** End **********/




  return 0;
}


