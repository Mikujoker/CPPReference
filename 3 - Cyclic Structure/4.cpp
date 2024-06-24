// 请在下方添加代码
/********** Begin *********/
#include<iostream>
using namespace std;
int main() 
{
  int n,m;
  cin >> n >> m;

  while(m != 0){
    int temp = n%m;
    n = m;
    m = temp;
  }

  cout << n;







  return 0;
}
/********** End **********/

