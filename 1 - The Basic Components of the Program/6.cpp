#include<iostream>
#include <stdio.h> 
using namespace std;
int main() 
{

    // 请在此添加代码
    /********** Begin *********/
    int seconds, hours, minutes, remainingSeconds;

    
    cin >> seconds;

    hours = seconds / 3600; // 1小时 = 3600秒
    minutes = (seconds % 3600) / 60; // 1分钟 = 60秒
    remainingSeconds = seconds % 60;

    cout << seconds << "秒为" << hours << "小时" << minutes << "分" << remainingSeconds << "秒" << endl;





    /********** End **********/




  return 0;
}


