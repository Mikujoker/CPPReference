// 请在下方添加代码
/********** Begin *********/
#include<iostream>
#include <cmath>
using namespace std;
int main() 
{
  int m,n;

  cin >> m >> n;

  int num1 = 0 ,num2 =0;


  for (int i = 0; i<4;i++){
    int digit1 = (m / static_cast<int>(pow(10, i))) % 10;
    int digit2 = (n / static_cast<int>(pow(10, i))) % 10;
    
    digit1 = (digit1 + 7) % 10;
    digit2 = (digit2 + 3) % 10;
    
    num1 += digit1 * static_cast<int>(pow(10, (i + 2) % 4));
    num2 += digit2 * static_cast<int>(pow(10, (i + 2) % 4));
  }
  cout << num1<<" " << num2;



  return 0;
}
/********** End **********/


