
#ifndef CLASS_H
#define CLASS_H

#include <vector>

using namespace std;

class Matrix {
public:
    vector<vector<int>> matrix;

    Matrix(int rows, int cols);
    void inputMatrix();
    void transpose();
    int determinant();
};

#endif
