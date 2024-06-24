#ifndef CLASS_H
#define CLASS_H

#include <string>

using namespace std;

class RomanWithInt {
public:

    RomanWithInt();

    int romanToInt(const string& s) const;

    string intToRoman(int num) const;

private:

    int getValue(char ch) const;
};

#endif // CLASS_H
