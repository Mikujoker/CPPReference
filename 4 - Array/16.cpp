#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int maxOnes = 0;
    int maxOnesRow = 0;
    int currentRow = 0;

    for (int i = 0; i < n; ++i) {
        int ones = 0;
        for (int j = 0; j < n; ++j) {
            int num;
            cin >> num;
            if (num == 1) {
                ones++;
            }
        }
        if (ones > maxOnes) {
            maxOnes = ones;
            maxOnesRow = currentRow;
        }
        if (ones == n){
            maxOnesRow = currentRow;
            break;
        }
        currentRow++;
    }

    cout << maxOnesRow;

    return 0;
}