#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void encrypt(string &p1, int Len2)
{
    int nums[] = {8, 7, 3, 4, 9, 6, 2};
    int output;
    int j;
    for (int i = 0; i < Len2; i++)
    {
        j = i % 7; // 修改索引计算为 i % 7
        output = p1[i] + nums[j];
        if (output > 122)
        {
            output = (output - 32) % 91 + 32;
        }
        p1[i] = static_cast<char>(output);
    }
}

void decrypt(string &p2, int Len1)
{
    int nums[] = {8, 7, 3, 4, 9, 6, 2};
    int output;
    int j;
    for (int i = 0; i < Len1; i++)
    {
        j = i % 7; // 修改索引计算为 i % 7
        output = p2[i] - nums[j];
        if (output < 32)
        {
            output =122-(31%output);
        }
        p2[i] = static_cast<char>(output);
    }
}

int main()
{
    string encry, decry;

    getline(cin, encry);  // 输入加密数组
    int Len2 = encry.size(); // 使用string::size()获取长度

    encrypt(encry, Len2); // 应用加密函数
    cout << encry <<endl;


    decrypt(encry, Len2); // 应用解密函数
    cout << encry << endl;

    return 0;
}