#include <iostream>
using namespace std;

bool isAlpha(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isSameAlpha(char ch1, char ch2) {
    return ch1 == ch2 || ch1 == ch2 + 32 || ch1 == ch2 - 32;
}

void updatePalindrome(char* a, int& begin_p, int& last_p, int j, int t, int i) {
    int t1 = 1, t2 = 1;
    while (j - t1 >= 0 && j + t + t2 <= i) {
        if (!isAlpha(a[j - t1])) {
            t1++;
            continue;
        }
        if (!isAlpha(a[j + t + t2])) {
            t2++;
            continue;
        }
        if (isSameAlpha(a[j - t1], a[j + t + t2])) {
            begin_p = j - t1;
            last_p = j + t + t2;
            t1++;
            t2++;
        } else {
            break;
        }
    }
}

int main() {
    char a[10000] = {0};
    int b[10000] = {0};
    int l[10000] = {0};
    char ch;
    int i = 0, j = 0;
    while ((ch = cin.get()) != EOF) {
        a[i] = ch;
        i++;
    }
    i -= 1;
    int m = 0;
    int begin_p = 0, last_p = 0;
    int even = 0;
    for (j = 0; j < i; j++) {
        even = 0;
        int t = 1;
        if (!isAlpha(a[j])) continue;
        while (!isAlpha(a[j + t])) t++;
        if (isSameAlpha(a[j], a[j + t])) even = 1;
        if (even == 1) {
            if (j == 0) {
                begin_p = 0;
                last_p = j + t;
            } else {
                updatePalindrome(a, begin_p, last_p, j, t, i);
            }
        } else {
            if (j == 0) {
                begin_p = last_p = 0;
            } else {
                updatePalindrome(a, begin_p, last_p, j, 0, i);
            }
        }
        if (begin_p != last_p) {
            b[m] = begin_p;
            l[m] = last_p;
            m++;
        }
    }
    int longest = 0;
    int y = 0, length1 = 0;
    for (int z = 0; z < m; z++) {
        for (int w = b[z]; w <= l[z]; w++)
            if (isAlpha(a[w])) length1 += 1;
        if (length1 > longest) {
            longest = length1;
            y = z;
        }
        length1 = 0;
    }
    int length = 0;
    for (int w = b[y]; w <= l[y]; w++)
        if (isAlpha(a[w])) length += 1;
    cout << length << endl;
    for (int w = b[y]; w <= l[y]; w++)
        cout << a[w];
    return 0;
}