#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int a, b;
    cin >> a >> b;

    int judging = 0;

    for (int i = a; i <= b; i++) {
        int num = i;
        int sum = 0;
        int digit_sum = 0;

        while (num > 0) {
            int digit = num % 10;
            sum += pow(digit, 3);
            num /= 10;
            digit_sum += 1;
        }

        if (sum == i) {
            judging = 1;
            cout << i << " ";
        }

        if (i >= 729 * digit_sum){
            break;
        }
    }

    if (judging == 0) {
        cout << "no";
    }

    return 0;
}