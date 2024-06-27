// 请在下方添加代码
/********** Begin *********/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i = 0;
    char str[80];

    while((str[i]=cin.get())!='\n')
        i++;
    str[i] = '\0';

    string uniqueChars = "";

    i = 0;
    while (str[i] != '\0') {
        int j = 0;
        while (uniqueChars[j] != '\0') {
            if (str[i] == uniqueChars[j]) {
                break;
            }
            j++;
        }
        if (uniqueChars[j] == '\0') {
            uniqueChars += str[i];
        }
        i++;
    }

    string sortedChars = "";
    for (int m = 127; m >= 0; --m) {
        for (int n = 0; n < uniqueChars.length(); ++n) {
            if (uniqueChars[n] == (char)m) {
                sortedChars += uniqueChars[n];
                break;
            }
        }
    }

    cout << sortedChars;

   
    return 0;
}
/********** End **********/