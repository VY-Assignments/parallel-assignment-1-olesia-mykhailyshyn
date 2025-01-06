#include <cstdlib>
#include <iostream>

const int matrixSize = 10;
int matrix[matrixSize][matrixSize];

int findMax(int matrix[matrixSize][matrixSize]) {
    int maxElement = INT_MIN;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
            }
        }
    }
    return maxElement;
}

int main () {

    std::cout << "MATRIX:" << std::endl;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrix[i][j] = rand();
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nMAIN DIAGONAL ELEMENTS:" << std::endl;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            if (i==j) {
                std::cout << matrix[i][j] << ", ";
            }
        }
    }

    std::cout << "\n\nMAX COLUMN ELEMENT:" << findMax(matrix) << std::endl;

    std::cout << "\nUPDATED MATRIX:" << std::endl;
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            if(i==j) {
                matrix[i][j] = findMax(matrix);
            }
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}