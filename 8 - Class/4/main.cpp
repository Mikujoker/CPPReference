#include <iostream>
#include "class.h"

using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;
    Matrix matrix(rows, cols);
    matrix.inputMatrix();
    matrix.transpose();
    int det = matrix.determinant();
    
    for (int i = 0; i < cols; ++i) {
        for (int j = 0; j < rows; ++j) {
            cout << matrix.matrix[i][j];
            if (j != rows - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    if (det == -1)  cout << "@" << endl;
    else    cout << det;
    
    return 0;
}