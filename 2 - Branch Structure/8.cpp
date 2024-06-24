// 请在下方添加代码
/********** Begin *********/
#include<iostream>
#include <cmath>

using namespace std;
int main() 
{
  int k,m;
  cin>>k;

  m = k;

  int n = 0;


  for(int i = 0;i<5;i++){
    n += m % 10 *pow(10,(4-i));
    m /= 10;

  }

  if (n == k)
      cout << "Yes";
  else{
    cout << "No";

  }
      





  return 0;
}
/********** End **********/

