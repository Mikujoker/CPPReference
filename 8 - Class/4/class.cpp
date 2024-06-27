#include <iostream>
#include <cstdio>
#include <cmath>
#include "class.h"
using namespace std;

Matrix::Matrix(int rows, int cols) {
    matrix.resize(rows);
    for (int i = 0; i < rows; ++i) {
        matrix[i].resize(cols);
    }
}

void Matrix::inputMatrix() {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cin >> matrix[i][j];
        }
    }
}

void Matrix::transpose() {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> transposedMatrix(cols, vector<int>(rows));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposedMatrix[j][i] = matrix[i][j];
        }
    }
    matrix = move(transposedMatrix);
}

int Matrix::determinant() {
    int rows = matrix.size();
    int cols = matrix[0].size();
    if (rows != cols) {
        return -1;
    }
    if (rows == 1) {
        return matrix[0][0];
    }
    int det = 0;
    for (int i = 0; i < rows; ++i) {
        Matrix subMatrix(rows - 1, cols - 1);
        for (int j = 1; j < rows; ++j) {
            for (int k = 0; k < cols; ++k) {
                if (k < i) {
                    subMatrix.matrix[j - 1][k] = matrix[j][k];
                } else if (k > i) {
                    subMatrix.matrix[j - 1][k - 1] = matrix[j][k];
                }
            }
        }
        det += ((i % 2 == 0) ? 1 : -1) * matrix[0][i] * subMatrix.determinant();
    }
    return det % 1000000007;
}