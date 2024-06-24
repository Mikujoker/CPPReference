#include<iostream>
#include <stdio.h>
#include <iomanip>
#include <cmath>
using namespace std;
int main() 
{

    // 请在此添加代码
    /********** Begin *********/
    int x1, y1, x2, y2;
    double distance;

    
    cin >> x1 >> y1;

    
    cin >> x2 >> y2;

    distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    cout << "(" << x1 << "," << y1 << ")和(" << x2 << "," << y2 << ")之间的距离是：";
    cout << fixed << setprecision(2) << distance << endl;



    /********** End **********/




  return 0;
}


