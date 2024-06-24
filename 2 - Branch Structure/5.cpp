// 请在下方添加代码
/********** Begin *********/
#include<iostream>

using namespace std;
int main() 
{
  float usage;
  cin >> usage;

  float fee;

  if (usage<=10)
    fee = 1.5 * usage;
    else
    fee = 1.5 * 10 + 2 * (usage - 10);
  
  cout << fee;
  





  return 0;
}
/********** End **********/

