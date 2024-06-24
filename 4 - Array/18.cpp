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
