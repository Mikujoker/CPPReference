// 请在下方添加代码
/********** Begin *********/
#include<iostream>
using namespace std;

int reverse(int x){
  int rev = 0;
    while (x > 0) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev;
}
int main() 
{
  int n;
  cin >> n;

  int num = 0;

  for(int i =0;i<=n;i++){
    int all = i + reverse(i);
    if (all == n){
      num += 1;

    }
    

  }
  cout << num;





  return 0;
}
/********** End **********/

