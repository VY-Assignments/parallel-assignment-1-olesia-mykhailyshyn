#include "matrix.h"

Matrix::Matrix(int matrixSize) : matrixSize(matrixSize), matrix(matrixSize, std::vector<int>(matrixSize)) {}

void Matrix::matrixCreation()  {
    srand(time(NULL));
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrix[i][j] = rand();
        }
    }
}

void Matrix::printMatrix() const {
    for(int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::printDiagonalElements() const {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            if (i == j && i + 1 == matrixSize) {
                std::cout << matrix[i][j] << ". ";
            }
            else if (i == j) {
                std::cout << matrix[i][j] << ", ";
            }
        }
    }
}

std::vector<std::vector<int>>& Matrix::getMatrix() {
    return matrix;
}