// 请在下方添加代码
/********** Begin *********/
#include<iostream>
using namespace std;
int main() 
{
  int ori;
  cin >> ori;

  int sum = ori;
  int t;

  for(int i = 0; i<10;i++){
    t = sum;
    sum = 0;
    while(t > 0){
      sum += t % 10;
      t /= 10;
    }

  }
  cout << sum;





  return 0;
}
/********** End **********/

