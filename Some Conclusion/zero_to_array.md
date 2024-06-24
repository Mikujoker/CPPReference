# 学习笔记

## 1. float.cpp文件
- 运算中产生浮点数的方式
- 保留有效数字的算法
```cpp
//这个代码表示两种保留浮点数后两位的操作
//顺带一提，可以适当地采用乘或除3.0这种来产生浮点数

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a = 3.1415926;
    
    cout << a << endl;
    
    //法1
    cout << setiosflags(ios::fixed) << setprecision(2) << a << endl;
    
    //法2
    cout << fixed << setprecision(2) << a << endl;
    
    return 0;
}
```

## 2. code.cpp文件
- 关注强制类型转换的方式
- n位数中对应位数的交换
```cpp
#include<iostream>
#include <cmath>
using namespace std;
int main() 
{
  int m,n;

  cin >> m >> n;

  int num1 = 0 ,num2 =0;


  for (int i = 0; i<4;i++){
    int digit1 = (m / static_cast<int>(pow(10, i))) % 10; 
    //主要注意的内容是这里pow函数得到的结果是double类型，需要强制转换

    //int digit1 = (m / int(pow(10, i))) % 10;这样也可以
    int digit2 = (n / static_cast<int>(pow(10, i))) % 10;
    
    digit1 = (digit1 + 7) % 10;
    digit2 = (digit2 + 3) % 10;
    
    num1 += digit1 * static_cast<int>(pow(10, (i + 2) % 4));
    //注意这里像这样对偶数个数做间隔x的交换，可以使用pow(10,(i + k) % n)
    num2 += digit2 * static_cast<int>(pow(10, (i + 2) % 4));
  }
  cout << num1<<" " << num2;



  return 0;
}
```

## 3. toggle case a to A.cpp
- 记住a和A的ASCII码差32

```cpp
#include<iostream>

using namespace std;
int main() 
{
  char ch;
  cin >> ch;

  if ('a'<= ch && 'z'>=ch)
      ch -= 32;
      //记住小写的a和大写的A的ASCII码相差32
      else if('A'<=ch && 'Z'>= ch)
      ch +=32;

  cout << ch;

  return 0;
}
```

## 4. palindrome.cpp
- 学会两种方法判断回文数

```cpp
#include<iostream>
#include <cmath>

using namespace std;

// 函数：通过字符串比较判断回文
bool isPalindromeString(string str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// 函数：通过数字反转判断回文
bool isPalindromeNumber(int num) {
    int reversedNum = 0;
    int originalNum = num;

    while (num != 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return originalNum == reversedNum;
}

int main() 
{
    string str;
    cin >> str;
    cout << (isPalindromeString(str) ? "Yes" : "No") << endl;

    int num;
    cin >> num;
    cout << (isPalindromeNumber(num) ? "Yes" : "No") << endl;

    return 0;
}
```

## 5. 题目隐式范围
>编写一个程序，读入两个正整数 `a` 和 `b`，并且 `a<=b`，计算并输出闭区间 `[a,b]` 中的 X 数。X 数为各个数位上数字的立方和等于其自身的数字。

```cpp
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int judging = 0;

    for (int i = a; i <= b; i++) {
        int num = i;
        int sum = 0;
        int digit_sum = 0;

        while (num > 0) {
            int digit = num % 10;
            sum += pow(digit, 3);
            num /= 10;
            digit_sum += 1;
        }

        if (sum == i) {
            judging = 1;
            cout << i << " ";
        }

        if (i >= 729 * digit_sum){
            break;//隐式范围
        }
    }

    if (judging == 0) {
        cout << "no";
    }

    return 0;
}
```
## 6.gcd.cpp
- 学会求最大公约数的recursive和iteration

```cpp
#include<iostream>
using namespace std;

int gcd_recursive(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
//迭代实现
int gcd_iteration(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
int main() 
{
  int n,m;
  cin >> n >> m;

  cout << gcd_recursive(n,m) << endl;
  cout << gcd_iteration(n,m) << endl;

  return 0;
}
```

## 7.dowhile.cpp

>本关任务：计算下列式子的和，当最后一项的值小于 $10^{-6}$ 时结束.
>
>$e = 1 + \frac{1}{1!} + \frac{1}{2!} + \ldots + \frac{1}{n!}$

```cpp
#include<iostream>
#include<iomanip>
using namespace std;
const double EPS = 1E-6;
int main() {
    int i, n;
    double item;
    double e;
    e = 1.0;
    n = 1;
    item = 1.0;
    do {
        
        item *= n;
        e += 1.0 / item;
        n++;
    } while (1.0 / item >= EPS);
    cout <<"e ="<<fixed << setprecision(6) << e << endl;
    return 0;
}
```

## 8.选择合适的循环方向

>假设有 n 件物品，物品 i 价值 i 美元，重量为 1 磅，小明的背包最多只能携带 W 磅重量，但他想买尽可能多地贵重物品。求他能带走的物品最大总价值。

```cpp
#include<iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    int totalValue = 0;
    int weight = 0;
    for (int i = n; i >= 1; i--) {
        //注意这里的循环方向
        if (weight + 1 <= W) {
            totalValue += i;
            weight += 1;
        } else {
            break;
        }
    }

    cout << totalValue;

    return 0;
}
```
## 9.状态改变问题

>本关任务：有 n 盏灯，编号为 1~n。第 1 个人把所有灯打开，第 2 个人按下所有编号为 2 的倍数的开关（这些灯将被关掉），第 3 个人按下所有编号为 3 的倍数的开关（其中关掉的灯将被打开，开着的灯将被关闭），依次类推。一共有 k 个人，问最后有哪些灯开着？编写一个程序，输入 n 和 k，输出开着的灯的编号（k≤n≤1000）。

```cpp
#include<iostream>

using namespace std;
int main() 
{
  int n,k;
  cin >> n >> k;

  bool lights[1001] = {false};

  for (int i = 1; i <= k; ++i) {
      for (int j = i; j <= n; j += i) {
          lights[j] = !lights[j];
      }
  }
//学会使用bool数组来进行状态判断和改变
  for (int i = 1; i <= n; ++i) {
        if (lights[i]) {
            cout << i << " ";
        }
    }
//修改和输出都从1开始，忽略了第0盏灯的状态
  cout << endl;


  return 0;
}
```

## 10.分数拆分和整数判断

>输入正整数 $k$，找到所有正整数 $x \geq y$，使得 $\frac{1}{k} = \frac{1}{x} + \frac{1}{y}$

```cpp
int k;
cin >> k;

for (int y = k+1;y<=2*k,y++){
    //注意此处循环条件及范围，利用了x>=y
    int x = k * y / (y - k);
    if (fabs(k * y * 1.0 / (y - k) - x) < 1e-3)//注意此处进行的浮点数转换和绝对值计算
        cout << "1/"<< k<<"=1/"<<x<<"+1/"<<y
}
```

## 11.闰年判断

- 如果年份能被4整除但不能被100整除，那么这一年就是闰年。
- 如果年份能被400整除，那么这一年也是闰年。

```cpp
bool isLeapYear(int year){
    bool leapyear;

    leapyear =(((year % 4 == 0)&&(year % 100 != 0))||(year % 400 == 0));

    return leapyear
}
```
### 延伸的小问题
>黑色星期五是指某天既是 13 号又是星期五。13 号在星期五比在其他日子少吗？为了回答这个问题，编写一个程序，计算每个月的 13 号落在周一到周日的次数。给出 n 年的一个周期，要求计算从 1900 年 1 月 1 日至 1900+n-1 年 12 月 31 日中 13 号落在周一到周日的次数，n 为正整数且不大于 400。（已知 1900 年 1 月 1 日是星期一）。

- 关注下列代码中对星期几出现次数的处理
- 保持一个星期几一直在某个范围内出现的方法
- 如何正确的获得某个月份的天数
  
```cpp
#include<iostream>

using namespace std;
int main() 
{
  int n;
  cin >> n;

  int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30, 31};
  int dayCount[7] = {0}; // 记录每个星期几出现的次数

  int dayOfWeek = 0; // 1900年1月1日是星期一
  for (int year = 1900; year < 1900 + n; ++year) {
      for (int month = 0; month < 12; ++month) {
          int days = daysInMonth[month];
          if (month == 1 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
              days = 29; // 闰年2月
          }
          for (int day = 1; day <= days; ++day) {
              if (day == 13) {
                  dayCount[dayOfWeek]++;
              }
              dayOfWeek = (dayOfWeek + 1) % 7;//正确的更新星期几，dayofweek始终处于0-6区间里
            }
        }
    }

  for (int i = 0; i < 7; ++i) {
      cout << dayCount[i] << " ";
  }




  return 0;
}
```

## 12.Hanoi塔

>最优算法——递归
>
>即将n-1个start -> temp
>
>再将最后一个start -> target
>
>最后将n-1个temp -> target

- 总移动次数$2^n - 1$

```cpp
void Hanoi(int n, char start, char target, char temp){
    if (n == 1)
        cout << start <<"->"<<target<<'\t';
    else{
        Hanoi(n-1,start,temp,target);
        cout << start <<"->"<<target<<'\t';
        Hanoi(n-1,temp,target,start);
    }
}
```

## 13.删除重复数据

>编写一个能删除数组中重复数据的程序

- 单数组版

```cpp
#include <iostream>

using namespace std;

int main() {
    int arr[100];
    int n = 0;
    int x;

    while (cin >> x) {
        bool isUnique = true;
        for (int i = 0; i < n; i++) {
            if (arr[i] == x) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            arr[n] = x;
            n++;
        }
    }

    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    

    return 0;
}
```
- 双数组版(注意，该版本疑似脱裤子fp)

```cpp
#include <iostream>

using namespace std;

int main() {
    int arr[100]; // 原始数组
    int uniqueArr[100]; // 用于存储唯一元素的新数组
    int n = 0; // 原始数组中元素的数量
    int m = 0; // 唯一元素的数量
    int x;

    // 读取输入数据并存储在arr中
    while (cin >> x) {
        arr[n] = x;
        n++;
    }

    // 从arr中找出唯一的元素并存储在uniqueArr中
    for (int i = 0; i < n; i++) {
        bool isUnique = true;
        for (int j = 0; j < m; j++) {
            if (uniqueArr[j] == arr[i]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            uniqueArr[m] = arr[i];
            m++;
        }
    }

    // 输出uniqueArr中的所有元素
    for (int k = 0; k < m; k++) {
        cout << uniqueArr[k] << " ";
    }

    return 0;
}
```

## 14. 优雅的进制转换方式

```cpp
// A进制的数转换为十进制
int convertToDecimal(string num, int A) {
    int result = 0;
    int length = num.length();
    for (int i = 0; i < length; i++) {
        char digit = num[i];
        int value = (digit >= '0' && digit <= '9') ? digit - '0' : digit - 'A' + 10;
        result += value * pow(A, length - i - 1);
    }
    return result;
}
//十进制转换为B进制
string convertToBase(int num, int B) {
    string result = "";
    while (num > 0) {
        int remainder = num % B;
        char digit = (remainder < 10) ? (char)(remainder + '0') : (char)(remainder - 10 + 'A');
        result = digit + result;
        num /= B;
    }
    return result;
}
```
<a name="big-number-factorial"></a>
## 15.利用数组进行大数的阶乘计算

```cpp
#include <iostream>
using namespace std;

int main() {
    int a[100000];
    int temp,digit,n,i,j=0;    
    //temp：每次的得数，digit：每次得数的位数
    while(cin>>n){
        a[0]=1;
        digit=1;
        for(i=2;i<=n;i++){
            int num=0;
            for(j=0;j<digit;j++){
                temp=a[j]*i+num;
                a[j]=temp%10;
                num=temp/10;
            }
            while(num){//用于进位
                a[digit]=num%10;
                num=num/10;
                digit++;
            }
        }
        for(i=digit-1;i>=0;i--)
            cout<<a[i];//从低到高输出结果
        cout<<endl;
    }
}
```
## 16.典中典之杨辉三角
- 迭代：这是最直观的方法，通过两层循环逐行计算杨辉三角的每个元素。每个元素等于它上一行的左上方和右上方两个元素之和。

- 递归：递归方法的思路是，要生成杨辉三角的第n行，先生成第n-1行，然后在第n-1行的基础上生成第n行。递归的基础情况是第0行和第1行。

- 动态规划：动态规划的思路是，用一个二维数组存储杨辉三角，每个元素只计算一次，并且在计算时可以利用已经计算过的元素。

- 数学公式：杨辉三角的每个元素都等于组合数C(n, k)，可以直接用组合数公式计算。但是这种方法在n较大时可能会因为计算阶乘导致溢出。

>请求出指定N时，该行的所有元素

```cpp
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int triangle[N][N]; // 定义一个二维数组来存储杨辉三角形

    // 初始化第一列和对角线上的元素为1
    for (int i = 0; i < N; i++) {
        triangle[i][0] = 1;
        triangle[i][i] = 1;
    }

    // 计算杨辉三角形中的其他元素
    for (int i = 2; i < N; i++) {
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }

    // 输出第N行的元素

    for (int i = 0; i < N; i++) {
        cout << triangle[N-1][i] << " ";
    }
    cout << endl;

    return 0;
}
```