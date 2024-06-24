#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int arr[1000]; // 假设最多输入 1000 个整数
    int uniqueArr[1000]; // 用于保存唯一的元素
    int count = 0; // 记录唯一元素个数

    int x;
    while (cin >> x) {
        bool found = false;
        for (int i = 0; i < count; ++i) {
            if (uniqueArr[i] == x) {
                found = true;
                break;
            }
        }
        if (!found) {
            uniqueArr[count] = x;
            count++;
        }
    }

    for (int k = 0; k < count; k++) {
        cout << uniqueArr[k] << " ";
    }
}