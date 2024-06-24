// 请在下方添加代码
/********** Begin *********/
#include <iostream>
using namespace std;

int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);

    int len1 = str1.length();
    int len2 = str2.length();
    int position = -1;

    for (int i = 0; i <= len1 - len2; ++i) {
        bool found = true;
        for (int j = 0; j < len2; ++j) {
            if (str1[i + j] != str2[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            position = i;
            break;
        }
    }

    cout << position << endl;



    return 0;
}
/********** End **********/