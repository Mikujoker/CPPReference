#include <iostream>
#include <string>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    vector<int> charIndex(128, -1);  // 初始化为 -1，表示字符尚未出现过
    int maxLength = 0;
    int start = 0;

    for (int end = 0; end < n; ++end) {
        if (charIndex[s[end]] != -1) {
            start = max(start, charIndex[s[end]] + 1);
        }
        charIndex[s[end]] = end;
        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}

int main() {
    string s;
    cin >> s;

    int maxLength = lengthOfLongestSubstring(s);
    cout << maxLength;

    return 0;
}