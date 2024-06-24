#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

struct Matrix {
    long long a, b, c, d;

    Matrix operator*(const Matrix& other) const {
        Matrix result;
        result.a = ((a * other.a) % MOD + (b * other.c) % MOD) % MOD;
        result.b = ((a * other.b) % MOD + (b * other.d) % MOD) % MOD;
        result.c = ((c * other.a) % MOD + (d * other.c) % MOD) % MOD;
        result.d = ((c * other.b) % MOD + (d * other.d) % MOD) % MOD;
        return result;
    }
};

// 调整为非负模数的函数
long long adjust(long long x) {
    return (x % MOD + MOD) % MOD;
}

Matrix matrixPower(Matrix m, long long n) {
    Matrix result = {1, 0, 0, 1}; // 单位矩阵
    while (n > 0) {
        if (n % 2 == 1) result = result * m;
        m = m * m;
        n /= 2;
    }
    return result;
}

int main() {
    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    Matrix m = {a, b, c, d};
    Matrix result = matrixPower(m, n);
    // 调整结果为非负数
    cout << adjust(result.a) << " " << adjust(result.b) << endl;
    cout << adjust(result.c) << " " << adjust(result.d) << endl;
    return 0;
}
