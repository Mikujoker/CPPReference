# 复习笔记

## 1.字符串交换
- 指针版本
```cpp
#include <iostream>
using namespace std;

int main()
{
    char str1[20];
    char str2[20];
    char c;
    char *cp;

    cin.getline(str1,20);
    cin.getline(str2,20);

    /*Start your code here*/
    for (cp = str1; cp < str1 + 20; cp++)
    {
        if (*cp == '\0' || *(cp - &str1[0] + &str2[0]) == '\0')
            break;//指针运算，它的目的是找到str2中与str1中当前字符对应的字符
            //cp - &str1[0]计算的是当前字符在str1中的位置（即索引），然后加上&str2[0]就得到了str2中对应字符的地址
        c = *cp;
        *cp = *(cp - &str1[0] + &str2[0]);
        *(cp - &str1[0] + &str2[0]) = c;
    }
    cout << str1 << endl;
    cout << str2 << endl;


    /*end your code*/
    return 0;
}
```

- 引用版本
```cpp
#include <iostream>
using namespace std;

int main()
{
    char str1[20];
    char str2[20];

    cin.getline(str1,20);
    cin.getline(str2,20);

    /*Start your code here*/
    for (int i = 0; i < 20; i++)
    {
        if (str1[i] == '\0' || str2[i] == '\0')
            break;
        swap(str1[i], str2[i]);
    }
    cout << str1 << endl;
    cout << str2 << endl;

    /*end your code*/
    return 0;
}
```

## 2.变换字符串顺序
```cpp
#include <iostream>
using namespace std;

int main()
{
    /*Start your code here*/
    string *arr, str, posString;
    arr = new string[11];
    int n = 0, *pos;
    getline(cin, str);
    int word_pos = 0, str_pos = 0, word = 0;
    bool isWord = false;
    while (str_pos < str.length())
    {
        if (str[str_pos] != ' ')
        {
            if (!isWord)
            {
                word_pos = str_pos;
                isWord = true;
            }
        }
        else
        {
            if (isWord)
            {
                isWord = false;
                arr[word] = string(&str[word_pos], &str[str_pos]);//依pos填充单词
                word++;
            }
        }
        str_pos++;
    }//查找单词的起始word和终止string_pos
    if (isWord)
    {
        isWord = false;
        arr[word] = string(&str[word_pos], &str[str_pos]);
        word++;
    }
    pos = new int[word];
    cin >> posString;
    cout << word << endl;
    for (int i = 0; i < word; i++)
        cout << arr[posString[i] - '0']<< ' ';//利用了pos是字符串数组
    delete[] arr;
    delete[] pos;
    


    /*end your code*/
    return 0;
}
```

## 3.典中典约瑟夫环

>n个人围成一圈，按顺序从1到n编号。从第一个人开始报数1、2、3，报到3的人退出圈子，下一个人从1开始重新报数，报到3的人退出圈子。如此进行下去，直到留下最后一个人。当给定一个正整数n时，请问留下来的人的编号是多少？


>算法如下
>
>假设我们有一个函数f(n)表示n个人的约瑟夫环问题的解。我们可以观察到以下规律：
>
>当n=1时，显然只有一个人，所以f(1)=1。
>
>当n>1时，第一轮报数后，编号为3的人会被淘汰，剩下的人形成一个新的约瑟夫环，人数为n-1。新的约瑟夫环的编号是从4开始的，所以我们可以将新的约瑟夫环的编号减3，得到一个人数为n-1，编号从1开始的约瑟夫环。这个约瑟夫环的解就是f(n-1)。然后我们再将解加3，得到原来约瑟夫环的解。但是，由于淘汰的是编号为3的人，所以解需要对n取模，得到f(n) = (f(n-1) + 3) % n。

- 好理解的递归法
```cpp
#include <iostream>
using namespace std;

int josephus(int n) {
    if (n == 1)
        return 1;
    else
        return (josephus(n - 1) + 3 - 1) % n + 1;
        //每一轮我们都会淘汰一个人，然后从下一个人开始重新编号。这就意味着，新的编号会比原来的编号偏移一位。例如，原来的编号是3的人被淘汰后，原来编号是4的人现在的编号就变成了3。

//所以，在递归公式中，我们需要减1来抵消这个偏移，然后在最后加1来恢复原来的编号。这就是为什么我们返回的是(josephus(n - 1) + 3 - 1) % n + 1，而不是(f(n-1) + 3) % n。
}

int main() {
    int n;
    cin >> n;
    cout << josephus(n) << endl;
    return 0;
}
```


- 简洁的迭代法
```cpp
#include <iostream>
using namespace std;

int josephus(int n) {
    int result = 0;
    for (int i = 2; i <= n; i++)
        result = (result + 3) % i;
    return result + 1;
}

int main() {
    int n;
    cin >> n;
    cout << josephus(n) << endl;
    return 0;
}
```
- 直观的模拟法
```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    /*Start your code here*/
    bool *p;
    
    int survive = n;
    p = new bool[n + 1];
    for (int i = 0; i < n + 1; i++)
        p[i] = true;
    int pos = 0;
    while (survive > 1)
    {
        int cnt = 3;
        while (cnt)//cnt变量表示当前还需要报多少次数。
        {
            pos++;
            if (pos > n)
                pos = 1;//pos++表示移动到下一个人。如果pos超过了n，就需要回到圈子的开始，所以pos被设置为1。
            if (p[pos])
                cnt--;//
        }
        p[pos] = false;//cnt变为0时，表示已经报了3次数，所以当前的人就需要退出圈子。这由p[pos] = false来表示。
        survive--;
    }
    for (int i = 1; i < n + 1; i++)
        if (p[i])
        {
            cout << i << endl;
            break;
        }

    delete[] p;


    /*end your code*/
    return 0;
}
```

## 4.难中难之敏感词过滤
>实现一个敏感词汇的程序。规则如下：
>
能接受的字符：①字母；②数字；③三个标点符号,."；④空格；⑤三个无用的符号@#$。
对于敏感信息的词汇不区分大小写。
要注意滤去可能在敏感词汇的中间出现的一些空格（比如要滤去lv，输入l v时要辨认出来并滤去）。
若有用信息（字母、数字）中夹杂着无用的符号，也要辨认出并滤去。假如敏感词汇是mz，那么m#z也要滤去，但是输入ml,z不用滤去。
要求说明：要过滤的词汇只有L4和Fd和D26这三个词，而且接受输入的字符串长度不大于20个字符。

```cpp
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

// // 检查敏感词汇，这里使用敏感词汇的小写版本
// bool is_sensitive(const string& str, const vector<int>& id, int pos, const string& word) {
//     int wlen = word.length();
//     if (pos + wlen - 1 >= id.size()) return false;
//     for (int i = 0; i < wlen; ++i) {
//         if (str[id[pos + i]] != word[i]) return false;
//     }
//     return true;
// }

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
```