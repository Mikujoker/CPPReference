# 学习笔记

## 1.isPrime
- 对于数n，判断它是否是素数，不必枚举 [2，n-1] 之间的数，只需要枚举[2, $\sqrt{n}$]之间的数即可。
```cpp
bool isPrime(int n){
    if(n == 1){
        return false;
    }
    int k = 2;
    while (k <= sqrt(n)){
        if (n % k == 0){
            return false;
        }
        k += 1;
    }
    return true;
    
}
```

## 2.潜泳问题

>某单位在某个湖里举行潜水比赛，这是一个团体项目，每一支队伍由n人组成，要求所有队员从A岸潜水到B岸。在潜水过程中必须用氧气瓶，但每支队伍只有一个氧气瓶。最多两个人同时使用一个氧气瓶，但此时两人必须同步前进，因此到达终点的时间等于较慢的一人单独从A到B的时间。大家都很Nice，随便两个人都愿意共用一个氧气瓶有用。请安排一种策略，让最后一名队员尽早到达终点。

>这个算法是解决一种特定问题的：有n个人需要过河，但是只有一艘船，船每次只能载两个人，每个人过河的速度不同，船的速度取决于两个人中较慢的那个。问题是如何安排才能使所有人尽快过河。

>以下是这个算法的详细步骤：
>
>如果人数n大于4，那么有两种策略：
>
>t1：最快的两个人先过河，最快的人带船回来，然后最慢的两个人过河，最快的人再带船回来。
t2：最快的人和第二快的人先过河，最快的人带船回来，然后最快的人和最慢的人过河，第二快的人带船回来。 这两种策略中，选择总时间较短的那个。

>如果人数n小于等于4，那么有特定的策略：
>
>当n为4时，有两种策略，选择总时间较短的那个。
>
>当n为3时，最快的人带其他两个人过河。
>
>当n为2时，两个人一起过河。
>
>当n为1时，这个人自己过河。

```cpp
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int swim(int a[], int n)
{
    if (n > 4)
    {
        int t1 = 2 * a[0] + a[n - 1] + a[n - 2];
        int t2 = a[0] + 2 * a[1] + a[n - 1];
        return swim(a, n - 2) + min(t1, t2);
    }
    else
    {
        switch (n)
        {
        case 4:
            return min(3 * a[1] + a[0] + a[3], a[2] + a[3] + 2 * a[0] + a[1]);
            break;
        case 3:
            return a[0] + a[1] + a[2];
            break;
        case 2:
            return a[0] + a[1];
            break;
        case 1:
            return a[0];
            break;
        }
    }
}
int main()
{
   	/*************begin***************/
    int n, p[1000], i;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> p[i];
    sort(p, p + n);
    cout << swim(p, n);
    return 0;
    
   /*************end******************/

    return 0;
}
```

## 3.典中典之Fibonacci

- 1.给出使用静态局部变量实现的fibonacci数
```cpp
int fib()
{
    static int a = 0, b = 1;
    int c = a + b;
    a = b; // 更新为下一个数字
    b = c; // 更新为下一个数字
    return a; // 返回当前计算出的斐波那契数
}
```
- 2.常见却低效的递归法
```cpp
int fib(int n) {
    if (n <= 2) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
```

- 3.动态规划法
```cpp
int fib(int n) {
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
```

## 4.阶乘

- 1.递归版本
```cpp
long long factorial(int n){
    if (n == 0){
        return 1;
    }else
        return n * factorial(n-1);
}
```
- 2.矩阵版本
[查看数组实现递归](zero_to_array.md#big-number-factorial)