#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <regex>

using namespace std;

bool is_valid_string(const string& str) {
    if (str.length() > 20) {
        return false;
    }
    for (char c : str) {
        if (!isalnum(c) && c != '.' && c != ',' && c != '"' && c != ' ' && c != '@' && c != '#' && c != '$') {
            return false;
        }
    }
    return true;
}

string to_lower_case(string str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = tolower(str[i]);
    }
    return str;
}

string removeSensitiveWords(string str) {
    regex l4_regex("l[@#$\\s]*4", regex_constants::icase);
    regex fd_regex("f[@#$\\s]*d", regex_constants::icase);
    regex d26_regex("d[@#$\\s]*2[@#$\\s]*6", regex_constants::icase);

    string prev_str;
    do {
        prev_str = str; // 保存当前字符串，以便于后面比较
        // 逐一替换掉敏感词汇
        str = regex_replace(str, l4_regex, "");
        str = regex_replace(str, fd_regex, "");
        str = regex_replace(str, d26_regex, "");
    } while (prev_str != str); // 如果字符串在一次循环后没有改变，说明已经移除了所有敏感词汇

    return str;
}

int main() {
    string input;

    getline(cin, input);

    if (!is_valid_string(input)) {
        cout << "输入不符合要求" << endl;
    } else {
        input = to_lower_case(input);
        input = removeSensitiveWords(input);
        cout << input;
    }

    return 0;
}
