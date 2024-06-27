- [ 第1关：个人成绩单类](#-第1关个人成绩单类)
- [ 第2关：坐标点类](#-第2关坐标点类)
- [ 第3关：时钟类](#-第3关时钟类)
- [ 第4关：简易矩阵类的实现](#-第4关简易矩阵类的实现)
- [ 第5关：大整数类](#-第5关大整数类)
- [ 第6关：复数类](#-第6关复数类)
- [ 第7关：罗马数字类](#-第7关罗马数字类)
- [ 第8关：复数类](#-第8关复数类)
### <span id="head1"> 第1关：个人成绩单类</span>

**Description**

实现一个个人成绩单类

**Note**

本题提供了main.cpp. class.h。你只需要编辑class.cpp，本题中不需要编辑其他文件。

**Input Format**

输入

输入多个在[0, 6]中的数字（用数字代表所需操作），（其中若输入0，紧接着后面输入三个整数：num1， num2， num3），用-1代表结束操作

**Output Format**
输出

相应操作的输出

**Sample Input**
```cpp
0 23 45 78
1
2
3
4
5
6
-1
```

**Sample Output**
```cpp
00000000 name 23 45 78
78
23
no
no
yes
```

**Explanation**
解释
在输入操作数之前，需提前创建好一个成绩单实例
0: 表示给三门课赋值
1: 将所有信息输出
2: 输出三门课中最高值
3: 输出三门课中最低值
4: 判断数学是否及格，若及格输出“yes”，否则输出“no”
5: 判断英语是否及格，若及格输出“yes”，否则输出“no”
6: 判断计算机是否及格，若及格输出“yes”，否则输出“no”


### <span id="head2"> 第2关：坐标点类</span>

**Description**

设计一个坐标类。默认坐标点应为（0, 0）

**Note**

本题提供了main.cpp. class.h。你只需要编辑class.cpp，本题中不需要编辑其他文件。

**Input Format**

输入

输入多个在[0, 9]中的数字（用数字代表所需操作），若相应操作需要值时，紧跟着输入, 用-1代表结束输入操作

**Output Format**
输出

相应操作的输出

**Sample Input**
```cpp
0
2 23
3 34
0
4 45 67
0
5
1
6 87
7 89
9
0
-1
```

**Sample Output**
```cpp
0 0
23 34
45 67
45 67
87 89
```

**Explanation**
解释
在输入操作数之前，需创建好了两个坐标点实例p，q
0：输出p坐标点横、纵坐标值，用空格隔开，换行结尾
1: 输出q坐标点横、纵坐标值，用空格隔开，换行结尾
2: 设定p的横坐标
3: 设定p的纵坐标
4: 设定p的横坐标及纵坐标
5: 将p的坐标值赋值给q
6: 设定q的横坐标
7: 设定q的纵坐标
8: 设定q的横坐标及纵坐标
9: 将q的坐标值赋值给p


### <span id="head3"> 第3关：时钟类</span>

**Description**

设计一个`hh:mm:ss`格式的时钟类，支持时间的修改和计算两个时间的差值(后者减前者的绝对值) 
使用给出的接口

**Note**

本题需要你编辑main.cpp, class.h, class.cpp三个文件  

**Input Format**

输入两个时间 计算差值（两个时间不保证先后顺序）

hh:mm:ss
hh:mm:ss

**Output Format**

时间的差值（绝对值）

以 `hh:mm:ss`的格式输出（注意前导0）

**Sample Input**
```cpp
10:30:25
14:20:34
```

**Sample Output**
```cpp
03:50:09
```

### <span id="head4"> 第4关：简易矩阵类的实现</span>

**Description**

编写一个简单的矩阵类Matrix，能实现mxn阶矩阵的初始化(Initialization)、转置(Transpose)并打印、以及方阵行列式(Determinant)的计算。依次输出转置矩阵，和行列式，如果没有行列式，输出字符@

**Note**

本题需要你编辑main.cpp, class.h, class.cpp三个文件

**Hint**

部分示例代码如下
```cpp
class Matrix {
public:
    void Initialization () {
      
    }
      void Transpose (){
      
    }
      int Determinant (   ){
      return 0;
    }
};
```

**Input Format**

第一行有两个整数，m，n 表示矩阵有m行，n列

接下来输入mxn个矩阵元素

**Sample Input1**
```cpp
2 3
1 3 4
2 4 5
```

**Sample Output1**
```cpp
1 2
3 4
4 5
@
```

**Sample Input2**
```cpp
2 2
1 3
2 4
```

**Sample Output2**
```cpp
1 2
3 4
-2
```

### <span id="head5"> 第5关：大整数类</span>

**Description**

要求实现BigInteger类  即能存储任意位数(不超过1000位)的非负整数
以私有成员形式存储非负数(int数组)本身和总位数
以成员函数形式从cin读入数据
以友元函数形式实现两个正数的加法，返回一个非负数(也是BigInteger对象)(不超过1000位)

**Input Format**

两行 不超过1000位的非负整数
**Output Format**

一行 两个非负整数的和

**Sample Input**
11111111111111111111111111111111111111111111111111111
99999999999999999999999999999999999999999999999999999

**Sample Output**
111111111111111111111111111111111111111111111111111110

### <span id="head6"> 第6关：复数类</span>

**Description**

实现一个存储复数(x + iy)的类 x与y为浮点数
要求实现

复数类的构造
复数的加法
复数的减法
复数的乘法
复数的除法

**Note**

本题需要你编辑main.cpp, class.h, class.cpp三个文件

**Input Format**

以x y形式输入两个复数

**Output Format**

依次输出复数的加法、减法、乘法、除法结果(保留两位小数)

**Sample Input**
1.0 2.0
2.0 3.0  

**Sample Output**
3.00 5.00
-1.00 -1.00
-4.00 7.00
0.62 0.08  

### <span id="head7"> 第7关：罗马数字类</span>

**Description**

罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

| 罗马数字 | 数值 |
|----------|------|
| I        | 1    |
| V        | 5    |
| X        | 10   |
| L        | 50   |
| C        | 100  |
| D        | 500  |
| M        | 1000 |

例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。

请编写一个罗马数字与整数的类RomanWithInt，类中函数能实现罗马数字与整数的相互转化。

**Note**

本题需要你编辑main.cpp, class.h, class.cpp三个文件

**Input Format**

若干行罗马数字与整型数字，顺序不定，

最后一行为@


**Sample Input**
```cpp
MCMXCIV
58
III
@
```

**Sample Output**
```cpp
1994
LVIII
3
```

### <span id="head8"> 第8关：复数类</span>

**Description**

实现一个有记录功能的简易加减表达式类。该类可以实现加法和减法以及记录表达式。

**Note**

本题只需要你编辑class.cpp。
请根据main.cpp和class.h来编写函数内容。

print_value函数打印value值。
print_total_expression函数打印总表达式。
print_self_expression函数打印该Calculator自带的表达式。
combine函数将传入的Calculator总表达式添加到this->total_expression后面，并且更新this->value的值。并且返回当前Calculator本身。

**Input Format**

三行，分别代表三个算子。算子example：
`+5`
`-1000`
每个算子只包含1个运算符号和符号后面的整数。



**Sample Input**
```cpp
+5
-100
-1000
```

**Sample Output**
```cpp
+5
+5
value is 5
+5-100
+5
value is -95
value is -2095
+5-100-1000-1000
```
