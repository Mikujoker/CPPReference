// 请在下方添加代码
/********** Begin *********/
#include<iostream>
#include <cmath>
using namespace std;
int main() 
{
  int a,n;
  cin >> a >> n;

  int current_term = a;
  int sum = 0;

  for (int i = 1; i <= n; i++) {
      sum += current_term;
      current_term = current_term * 10 + a;
  }
  cout << sum;

  return 0;





  return 0;
}
/********** End **********/

