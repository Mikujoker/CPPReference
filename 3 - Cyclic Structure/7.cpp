// 请在下方添加代码
/********** Begin *********/
#include<iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n, W;

    cin >> n >> W;

    int totalValue = 0;
    int weight = 0;
    for (int i = n; i >= 1; i--) {
        if (weight + 1 <= W) {
            totalValue += i;
            weight += 1;
        } else {
            break;
        }
    }

    cout << totalValue;


  return 0;
}
/********** End **********/

