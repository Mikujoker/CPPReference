#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

bool is_valid_string(const string& str) { // 用于检查输入是否合法
    if (str.length() > 20) {
        return false;
    }
    for (char c : str) {
        if (!isalnum(c) && c != '.' && c != ',' && c != '"' && c != ' ' && c != '@' && c != '#' && c != '$') { // 修正了条件判断中的错误
            return false;
        }
    }
    return true;
}

string to_lower_case(string str) { // 用于将输入全部转化为小写字符
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = tolower(str[i]);
    }
    return str;
}

bool is_valid(char i) {
    if (isalnum(i) || i == '.' || i == ',' || i == '"' || i == ' ' || i == '@' || i == '#' || i == '$') { // 调整判断逻辑以包括所有有效字符
        return true;
    }
    return false;
}

// 检查敏感词汇，这里使用敏感词汇的小写版本
bool is_sensitive(const string& str, const vector<int>& id, int pos, const string& word) {
    int wlen = word.length();
    if (pos + wlen - 1 >= id.size()) return false;
    for (int i = 0; i < wlen; ++i) {
        if (str[id[pos + i]] != word[i]) return false;
    }
    return true;
}

string removeSensitiveChars(string str) {
    string result; // 用于构建最终的字符串
    bool found;
    do {
        vector<int> id; // 有效字符的下标数组
        for (int pos = 0; pos < str.length(); pos++) {
            if (isalnum(str[pos])) { // 只考虑字母和数字为有效字符
                id.push_back(pos);
            }
        }

        vector<bool> toDelete(str.length(), false); // 标记需要删除的字符
        found = false;

        for (int i = 0; i < id.size(); ++i) {
            // 检查敏感词汇
            string temp; // 用于收集从当前位置开始的有效字符序列
            for (int j = i; j < id.size(); ++j) {
                temp += str[id[j]];
                // 检查temp是否包含敏感词汇
                if (temp == "l4" || temp == "fd" || temp == "d26") {
                    // 标记这段区间的字符为删除
                    for (int k = id[i]; k <= id[j]; ++k) {
                        toDelete[k] = true;
                    }
                    found = true;
                    break; // 找到敏感词汇后跳出循环
                }
            }
        }

        result.clear();
        for (int i = 0; i < str.length(); ++i) {
            if (!toDelete[i]) {
                result += str[i];
            }
        }

        str = result; // 更新str以进行下一轮检查
    } while (found); // 如果这一轮找到并标记了敏感词汇，则继续检查

    return result;
}

int main() {
    string input;

    getline(cin, input);

    if (!is_valid_string(input)) {
        cout << "输入不符合要求" << endl;
        return 0;
    }

    input = to_lower_case(input);
    string output = removeSensitiveChars(input);
    cout << output;

    return 0;
}
