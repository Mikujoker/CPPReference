#include <iostream>
#include "class.h"

using namespace std;

int main() {
    RomanWithInt converter;
    string input;
    
    while (cin >> input && input != "@") {
        if (isdigit(input[0])) {
            int num = stoi(input);
            cout << converter.intToRoman(num) << endl;
        } else {
            cout << converter.romanToInt(input) << endl;
        }
    }
    
    return 0;
}
