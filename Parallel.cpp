#include "Parallel.h"
#include <iostream>
#include <climits>
#include <vector>
#include <thread>

void Parallel::findMaxInColumn(const std::vector<std::vector<int>>& matrix, int column, std::vector<int>& maxElements) {
    int maxElement = INT_MIN;
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[i][column] > maxElement) {
            maxElement = matrix[i][column];
        }
    }
    maxElements[column] = maxElement;
}

void Parallel::findMaxPerColumn(const std::vector<std::vector<int>>& matrix, std::vector<int>& maxElements) {
    int matrixSize = matrix.size();
    maxElements.resize(matrixSize);

    std::vector<std::thread> threads;

    for (int i = 0; i < matrixSize; i++) {
        threads.emplace_back(findMaxInColumn, std::cref(matrix), i, std::ref(maxElements));
    }

    for (size_t i = 0; i < threads.size(); i++) {
        threads[i].join();
    }
}

void Parallel::printMaxPerColumn(const std::vector<int>& maxElements) {
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

void Parallel::updateMatrixDiagonalElement(std::vector<std::vector<int>>& matrix, int column, const std::vector<int>& maxElements) {
    for (int i = 0; i < matrix.size(); i++) {
        if (column == i) {
            matrix[i][column] = maxElements[i];
        }
    }
}

void Parallel::updateMatrixDiagonalElements(std::vector<std::vector<int>>& matrix, const std::vector<int>& maxElements) {int matrixSize = matrix.size();
    std::vector<std::thread> threads;

    for (int i = 0; i < matrixSize; i++) {
        threads.emplace_back(&Parallel::updateMatrixDiagonalElement, std::ref(matrix), i, std::cref(maxElements));
    }

    for (size_t i = 0; i < threads.size(); i++) {
        threads[i].join();
    }
}