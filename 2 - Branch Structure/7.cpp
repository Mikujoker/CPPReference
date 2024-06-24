// 请在下方添加代码
/********** Begin *********/
#include<iostream>

using namespace std;
int main() 
{
  char carType;
    int inTime, outTime;
    int hours, totalFee;

    cin >> carType >> inTime >> outTime;
    
    hours = outTime - inTime;

    if (carType == 'c') {
        
        if (hours <= 3) {
            totalFee = hours * 5;
        } else {
            totalFee = 3 * 5 + (hours - 3) * 10;
        }
    } else if (carType == 'b') {
        
        if (hours <= 2) {
            totalFee = hours * 10;
        } else {
            totalFee = 2 * 10 + (hours - 2) * 15;
        }
    } else if (carType == 't') {
        
        if (hours <= 1) {
            totalFee = hours * 10;
        } else {
            totalFee = 1 * 10 + (hours - 1) * 15;
        }
    } 
    cout << totalFee;





  return 0;
}
/********** End **********/

