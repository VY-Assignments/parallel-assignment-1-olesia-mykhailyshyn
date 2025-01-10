#include "Sequential.h"
#include <climits>

void Sequential::findMaxPerColumn(const std::vector<std::vector<int>>& matrix, std::vector<int>& maxElements) {
    int matrixSize = matrix.size();
    maxElements.resize(matrixSize);

    for (int j = 0; j < matrixSize; ++j) {
        int maxElement = INT_MIN;
        for (int i = 0; i < matrixSize; ++i) {
            if (matrix[i][j] > maxElement) {
                maxElement = matrix[i][j];
            }
        }
        maxElements[j] = maxElement;
    }
}

void Sequential::printMaxPerColumn(const std::vector<int>& maxElements) {
    for (size_t i = 0; i < maxElements.size(); ++i) {
        std::cout << maxElements[i];
        if (i < maxElements.size() - 1) {
            std::cout << ", ";
        }
        else {
            std::cout << ".";
        }
    }
    std::cout << std::endl;
}

void Sequential::updateMatrixDiagonalElements(std::vector<std::vector<int>>& matrix, const std::vector<int>& maxElements) {
    for (int i = 0 ; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            if(i==j) {
                matrix[i][j] = maxElements[i];
            }
        }
    }
}