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