#include "class.h"
#include <cstring>

using namespace std;

BigInteger::BigInteger() : length(0) {
    digits = new int[MAX_DIGITS];
    for (int i = 0; i < MAX_DIGITS; ++i) {
        digits[i] = 0;
    }
}

BigInteger::BigInteger(const string &num) {
    length = num.size();
    digits = new int[MAX_DIGITS];
    for (int i = 0; i < MAX_DIGITS; ++i) {
        digits[i] = 0;
    }
    for (int i = 0; i < length; ++i) {
        digits[i] = num[length - 1 - i] - '0';
    }
}

BigInteger::BigInteger(const BigInteger &other) {
    length = other.length;
    digits = new int[MAX_DIGITS];
    for (int i = 0; i < MAX_DIGITS; ++i) {
        digits[i] = other.digits[i];
    }
}

BigInteger::~BigInteger() {
    delete[] digits;
}

void BigInteger::read() {
    string num;
    cin >> num;
    *this = BigInteger(num);
}

BigInteger add(const BigInteger &a, const BigInteger &b) {
    BigInteger result;
    int maxLength = max(a.length, b.length);
    int carry = 0;

    for (int i = 0; i < maxLength; ++i) {
        int digitA = (i < a.length) ? a.digits[i] : 0;
        int digitB = (i < b.length) ? b.digits[i] : 0;

        int sum = digitA + digitB + carry;
        result.digits[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0) {
        result.digits[maxLength] = carry;
        result.length = maxLength + 1;
    } else {
        result.length = maxLength;
    }

    return result;
}

ostream& operator<<(std::ostream &out, const BigInteger &num) {
    for (int i = num.length - 1; i >= 0; --i) {
        out << num.digits[i];
    }
    return out;
}

BigInteger& BigInteger::operator=(const BigInteger &other) {
    if (this == &other) {
        return *this;
    }

    delete[] digits;

    length = other.length;
    digits = new int[MAX_DIGITS];
    for (int i = 0; i < MAX_DIGITS; ++i) {
        digits[i] = other.digits[i];
    }

    return *this;
}
