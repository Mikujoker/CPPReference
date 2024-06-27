// 请在下方添加代码
/********** Begin *********/
#include<iostream>
#include<iomanip>
using namespace std;
const double EPS = 1E-6;
int main() {
    int i, n;
    double item;
    double e;
    e = 1.0;
    n = 1;
    item = 1.0;
    do {
        
        item *= n;
        e += 1.0 / item;
        n++;
    } while (1.0 / item >= EPS);
    cout <<"e ="<<fixed << setprecision(6) << e << endl;
    return 0;
}
/********** End **********/

