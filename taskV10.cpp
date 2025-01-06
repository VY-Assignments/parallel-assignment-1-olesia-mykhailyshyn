#include <cstdlib>
#include <iostream>
#include <chrono>

const int matrixSize = 10;
int matrix[matrixSize][matrixSize];

void matrixCreation(int matrixSize) {
    srand(time(NULL)); //time(NULL) will always be different for every instance of the program OR 0????
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            matrix[i][j] = rand();
            //std::cout << matrix[i][j] << " ";
        }
        //std::cout << std::endl;
    }
}

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

void printDiagonalElements(int matrix[matrixSize][matrixSize]) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            if (i==j) {
                std::cout << matrix[i][j] << ", ";
            }
        }
    }
}

void updateMatrixDiagonalElements (int matrix[matrixSize][matrixSize]) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            if(i==j) {
                matrix[i][j] = findMax(matrix);
            }
            //std::cout << matrix[i][j] << " ";
        }
        //std::cout << std::endl;
    }
}

void printMatrix(int matrix[matrixSize][matrixSize]) {
    for(int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main () {
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;

    start = std::chrono::high_resolution_clock::now();
    std::cout << "MATRIX:" << std::endl;
    matrixCreation(matrixSize);
    printMatrix(matrix);

    std::cout << "\nMAIN DIAGONAL ELEMENTS:" << std::endl;
    printDiagonalElements(matrix);

    std::cout << "\n\nMAX COLUMN ELEMENT:" << findMax(matrix) << std::endl;

    std::cout << "\nUPDATED MATRIX:" << std::endl;
    updateMatrixDiagonalElements(matrix);
    printMatrix(matrix);

    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::high_resolution_clock::to_time_t(end);

    std::cout << "\nFINISHED COMPUTATION AT " << std::ctime(&end_time) << "ELAPSED TIME: " << elapsed_seconds.count() << "s" << std::endl;

    return 0;
}