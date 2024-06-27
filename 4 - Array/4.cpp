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