#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool is_valid_string(const string& str) {//用于检查输入是否合法
    if (str.length() > 20) {
        return false;
    }
    for (char c : str) {
        if (!isalnum(c) && c != '.' && c != ',' && c != '"' && c != ' ' && c != '@' && c != '#' && c != '$') { // 修正了括号匹配问题
            return false;
        }
    }
    return true;
}

string to_lower_case(string str) {//用于将输入全部转化为小写字符
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = tolower(str[i]); 
    }
    return str;
}

// 修正了findChar函数，使其能够正确跳过无用符号并找到目标字符
size_t findChar(const string& str, char target, size_t start) {
    size_t pos = start;
    while (pos < str.length()) {
        if (str[pos] == target) {
            return pos;
        }
        if (str[pos] == '@' || str[pos] == ' ' || str[pos] == '#' || str[pos] == '$') {
            pos++;
        } else {
            break;
        }
    }
    return string::npos;
}

string removeSensitiveChars(const string& input) {
    string result = input;
    bool foundSensitive;

    do {
        foundSensitive = false;
        size_t pos = 0;

        while (pos < result.length()) {
            size_t start;
            char target;
            char except = '\0'; // 初始化except字符，以便后面使用

            if (result[pos] == 'l') {
                start = pos;
                target = '4';
            } else if (result[pos] == 'd') {
                start = pos;
                target = '2';
                except = '6'; // 特殊处理d26
            } else if (result[pos] == 'f') {
                start = pos;
                target = 'd';
            } else {
                pos++;
                continue;
            }

            size_t foundPos = findChar(result, target, pos + 1);
            if (foundPos != string::npos) {
                if (except != '\0') { // 处理d26的情况
                    size_t foundExcept = findChar(result, except, foundPos + 1);
                    if (foundExcept != string::npos) {
                        result.erase(start, foundExcept - start + 1);
                        foundSensitive = true;
                        continue; // 继续处理下一个字符
                    }
                } else {
                    result.erase(start, foundPos - start + 1);
                    foundSensitive = true;
                    continue; // 继续处理下一个字符
                }
            }
            pos++;
        }

    } while (foundSensitive); // 如果这一轮找到并标记了敏感词汇，则继续检查

    return result;
}

int main() {
    string input;
    
    getline(cin, input);

    if (!is_valid_string(input)) {
        cout << "输入不符合要求" << endl;
    } else {
        input = to_lower_case(input);
        input = removeSensitiveChars(input);
        cout << input;
    }

    return 0;
}
