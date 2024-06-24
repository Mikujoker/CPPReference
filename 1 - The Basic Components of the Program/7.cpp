#include<iostream>
#include <stdio.h> 
#include <iomanip>

using namespace std;
int main() 
{

    // 请在此添加代码
    /********** Begin *********/
    int radius;
    const double pi = 3.14;

    cin >> radius;

    double surfaceArea = 4 * pi * radius * radius;
    double volume = (4.0 / 3.0) * pi * radius * radius * radius;

    cout << fixed << setprecision(1);
    cout << "半径为" << radius << "的球体积为" << volume << endl;
    cout << "半径为" << radius << "的球体表面积为" << surfaceArea << endl;



    /********** End **********/




  return 0;
}


