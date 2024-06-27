// 请在下方添加代码
/********** Begin *********/
#include<iostream>

using namespace std;
int main() 
{
  int n,k;
  cin >> n >> k;

  bool lights[1001] = {false};

  for (int i = 1; i <= k; ++i) {
      for (int j = i; j <= n; j += i) {
          lights[j] = !lights[j];
      }
  }

  for (int i = 1; i <= n; ++i) {
        if (lights[i]) {
            cout << i << " ";
        }
    }

  cout << endl;





  return 0;
}
/********** End **********/

