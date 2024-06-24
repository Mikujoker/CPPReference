#include <iostream>
using namespace std;

void printInt(int n, int base){
    string result = "";
    while (n > 0) {
        int remainder = n % base;
        char digit = (remainder < 10) ? (char)(remainder + '0') : (char)(remainder - 10 + 'A');
        result = digit + result;
        n /= base;
    }
    cout << result << endl;
}

int main() {
    int n, base;
    
    cin >> n >> base;
    printInt(n, base);
    return 0;
}