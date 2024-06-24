#include "class.h"

using namespace std;

RomanWithInt::RomanWithInt() {}

int RomanWithInt::getValue(char ch) const {
    switch (ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int RomanWithInt::romanToInt(const string& s) const {
    int total = 0;
    int prevValue = 0;
    
    for (int i = s.size() - 1; i >= 0; --i) {
        int value = getValue(s[i]);
        if (value < prevValue) {
            total -= value;
        } else {
            total += value;
        }
        prevValue = value;
    }
    
    return total;
}

string RomanWithInt::intToRoman(int num) const {
    const pair<int, string> valueSymbols[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    
    string result;
    for (const auto& pair : valueSymbols) {
        while (num >= pair.first) {
            result += pair.second;
            num -= pair.first;
        }
    }
    
    return result;
}
