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

void Parallel::findMaxPerColumn(const std::vector<std::vector<int>>& matrix, std::vector<int>& maxElements, int maxThreads) {
    int matrixSize = matrix.size();
    maxElements.resize(matrixSize);

    auto worker = [&](int startCol, int endCol) {
        for (int col = startCol; col < endCol; ++col) {
            int maxElement = INT_MIN;
            for (int i = 0; i < matrix.size(); i++) {
                if (matrix[i][col] > maxElement) {
                    maxElement = matrix[i][col];
                }
            }
            maxElements[col] = maxElement;
        }
    };

    std::vector<std::thread> threads;
    int colsPerThread = (matrixSize + maxThreads - 1) / maxThreads;

    for (int i = 0; i < maxThreads; ++i) {
        int startCol = i * colsPerThread;
        int endCol = std::min(startCol + colsPerThread, matrixSize);
        if (startCol < matrixSize) {
            threads.emplace_back(worker, startCol, endCol);
        }
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

void Parallel::updateMatrixDiagonalElements(std::vector<std::vector<int>>& matrix, const std::vector<int>& maxElements, int maxThreads) {
    int matrixSize = matrix.size();

    auto worker = [&](int startRow, int endRow) {
        for (int row = startRow; row < endRow; ++row) {
            matrix[row][row] = maxElements[row];
        }
    };

    std::vector<std::thread> threads;
    int rowsPerThread = (matrixSize + maxThreads - 1) / maxThreads;

    for (int i = 0; i < maxThreads; ++i) {
        int startRow = i * rowsPerThread;
        int endRow = std::min(startRow + rowsPerThread, matrixSize);
        if (startRow < matrixSize) {
            threads.emplace_back(worker, startRow, endRow);
        }
    }

    for (size_t i = 0; i < threads.size(); i++) {
        threads[i].join();
    }
}