# 学习笔记

## 1.读取字符串方法

- 读取字符串的方法之一
- 学会通过与'0'相减将字符转化为整数
```cpp
#include <iostream>
using namespace std;

int main(){
    int i, j, n = 0;
    char str[80];

    i = 0;
    while((str[i]=cin.get())!='\n')
        i++;
    str[i] = '\0';//获得字符串的方法，注意最后补上了'/0'

    for(j = 0; str[j]!=0; j++){
        if(str[j]>='0'&& str[j]<='9')
            n = n*10 + (str[j] - '0');
    }
    cout << n << endl;
    return 0;
}
```

## 2.优雅的遍历方法
- cin.getline()会自动将\n替换为\0
  
- 关注for循环內部
```cpp
#include <iostream>
#include <string>
using namespace std;

int main(){
    int i = 0;
    char str[80];

    cin.getline(str,80);
    

    string vowels = "AEIOUaeiou";
    int count = 0;
    for (char n : str) {
        for (char v : vowels) {
            if (n == v) {
                count++;
                break;
            }
        }
    }

    cout << "Count="<<count;
    
	
	
	
    return 0;
}
```
- 当然另一种遍历方法就是while(str[n] != '\0')
- 还要会用下面这个
  ```cpp
    cin >> n;
    cin.ignore(); // 忽略输入缓冲区中的换行符
    ```

## 3. 字符串依ASCII码排序
- 关注重复删除
- 关注ASCII码排序思路
```cpp

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int i = 0;
    char str[80];

    while((str[i]=cin.get())!='\n')
        i++;
    str[i] = '\0';

    //删除重复
    string uniqueChars = "";
    i = 0;
    while (str[i] != '\0') {
        int j = 0;
        while (uniqueChars[j] != '\0') {
            if (str[i] == uniqueChars[j]) {
                break;
            }
            j++;
        }
        if (uniqueChars[j] == '\0') {
            uniqueChars += str[i];
        }
        i++;
    }
    //依ASCII码排序
    string sortedChars = "";
    for (int m = 127; m >= 0; --m) {
        //127（ASCII 码的最大值）
        for (int n = 0; n < uniqueChars.length(); ++n) {
            if (uniqueChars[n] == (char)m) {
                sortedChars += uniqueChars[n];
                break;
            }
        }
    }

    cout << sortedChars;

   
    return 0;
}
```

## 4.isdigit/alpha/space
- 可能需要你学会用这几个函数
```cpp
#include <iostream>
using namespace std;

int main()
{
    int n;
    
    cin >> n;
    cin.ignore(); // 忽略输入缓冲区中的换行符

    string inputText = "";
    
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        inputText += line;
    }

    int letterCount = 0;
    int digitCount = 0;
    int otherCount = 0;
    for (int i = 0; i < inputText.length(); ++i) {
        if (isalpha(inputText[i])) {
            letterCount++;
        } else if (isdigit(inputText[i])) {
            digitCount++;
        } else if (!isspace(inputText[i])) {
            otherCount++;
        }
    }


    cout << "英文字母：" << letterCount << "\n数字："<<digitCount<<"\n其他字符："<<otherCount;
	
```
## 5.无重复字符串长度（索引的思想）

```cpp
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
            start = max(start, charIndex[s[end]] + 1);//新的起始位置是当前字符上次出现的位置加一和当前起始位置中的较大值。
        }
        charIndex[s[end]] = end;
        maxLength = max(maxLength, end - start + 1);//用于更新最长无重复字符子串的长度。
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
```

## 6.经典排序算法
- 选择排序
```cpp
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    int i, j, minIndex, tmp;    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[minIndex])
                minIndex = j;
        if (minIndex != i) {
            tmp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tmp;
        }
    }
}
```

- 冒泡排序
```cpp
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
```
- 插入排序
```cpp
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // 插入排序算法
    for (int i = 1; i < n; ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && key < nums[j]) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = key;
    }

    // 输出排序后的元素
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }

    return 0;
}
```
- 快速排序
```cpp
#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
```
## 7. 回文字符串

>本关任务：编写一个程序，寻找一篇英文文章中最长的回文字符串。
>
>回文字符串是具有回文特性的字符串：即该字符串从左向右读，与从右向左读都一样。
>
>输入文件不会超过10000字符。这个文件可能一行或多行，但是每行都不超过80个字符（不包括最后的换行符）。在寻找回文时只考虑字母 'A' - 'Z' 和 'a' - 'z' ，忽略其他字符（例如：标点符号，空格等）。
>
>输出的第一行应该包括找到的最长的回文的长度。下一行或几行应该包括这个回文的原文（没有除去标点符号，空格等），把这个回文输出到一行或多行（如果回文中包括换行符）。如果有多个回文长度都等于最大值，输出最前面出现的那一个。注意，输出时需要去除回文两端的其他字符。

>典中典之Confucius say: Madam, I'm Adam.

```cpp
#include <iostream>
using namespace std;

bool isAlpha(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
//函数1——判断是否为字符

bool isSameAlpha(char ch1, char ch2) {
    return ch1 == ch2 || ch1 == ch2 + 32 || ch1 == ch2 - 32;
}
//函数2——忽略大小写判断字符是否一致

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
```

## 8.亏贼之点灯加强版

>本关任务：5*5的格子中，每个格子代表一盏灯，点击一次，此格子和上下左右相邻的共5个格子中的灯的状态会发生反转，亮着的会熄灭，熄灭的会点亮。如何用最少的点击次数使所有的灯都点亮？（亮灯用1表示，熄灭状态用0表示）

```cpp
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

#define N 5
bool change[N + 2][N + 2] = {false};
//设置N+2是为了正确改变第1.n行列的状态

void change_bit(int m, int n)
{
    change[m][n] = !change[m][n];
    change[m + 1][n] = !change[m + 1][n];
    change[m - 1][n] = !change[m - 1][n];
    change[m][n + 1] = !change[m][n + 1];
    change[m][n - 1] = !change[m][n - 1];
}
int main()
{
    char ch;
    bool origin[N + 2][N + 2] = {false};
    bool isSuccessful = false;
    int min = N * N;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
        {
            cin >> ch;
            if (ch == '1')
                origin[i][j] = true;
        }

    for (int i = 0; i < (1 << N); i++)
    {//注意这里表示循环2^n次，i以十进制表示2进制，实质上是第一行的状态表示
    //例如110（6）：点击第二个和第三个灯
        memcpy(change, origin, sizeof(origin));
        int cnt = 0;
        int temp = i;
        bool thisisSuccessful = true;
        for (int j = N; j >= 1; j--)
        {
            if (temp % 2 == 1)
            {
                change_bit(1, j);
                cnt++;
            }
            temp /= 2;
        }//这一步其实就是把i解析为第一行的电灯方式
        for (int j = 2; j <= N; j++)
            for (int k = 1; k <= N; k++)
            {
                if (change[j - 1][k] == false)
                {
                    change_bit(j, k);
                    cnt++;
                }
            }

        for (int j = 1; j <= N; j++)
        {
            if (change[N][j] == false)
            {
                thisisSuccessful = false;
                break;
            }
        }
        if (thisisSuccessful)
        {
            isSuccessful = true;
            if (min > cnt)
                min = cnt;
        }
    }
    if (isSuccessful)
        cout << min << endl;
    else
        cout << "-1" << endl;
    return 0;
}
```