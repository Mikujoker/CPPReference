// 请在下方添加代码
/********** Begin *********/
#include<iostream>

using namespace std;

  bool isPalindrome(string str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    int B;
    
    cin >> B;

    string baseB[200];
    string squareB[200];

    int count = 0;
    for (int i = 1; i <= 200; i++) {
        int square = i * i;
        string base = "";
        string squareStr = "";

        int num = i;
        while (num > 0) {
            int remainder = num % B;
            char digit = (remainder < 10) ? (char)(remainder + '0') : (char)(remainder - 10 + 'A');
            base = digit + base;
            num /= B;
        }

        num = square;
        while (num > 0) {
            int remainder = num % B;
            char digit = (remainder < 10) ? (char)(remainder + '0') : (char)(remainder - 10 + 'A');
            squareStr = digit + squareStr;
            num /= B;
        }

        if (isPalindrome(squareStr)) {
            baseB[count] = base;
            squareB[count] = squareStr;
            count++;
        }
    }

    for (int i = 0; i < count; i++) {
        cout << baseB[i] << " " << squareB[i] << endl;
    }






  return 0;
}
/********** End **********/

