#include <iostream>

using namespace std;


int Magic(int m){
   /***********begin************/
    for (int i = 1; i <= 9; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (122 * i + 212 * j + 221 * k == m)
                    return (100 * i + 10 * j + k);
   return -1;
   /***********end**************/
}

int main()
{
    int t,m;
    cin >> t;
    while(t--){
        cin >> m;
        int res = Magic(m);
        if(res == -1) {
            cout << "The sum you calculated is wrong!\n";
        } else {
            cout << "The number is " << res << endl;
        }
    }
}
