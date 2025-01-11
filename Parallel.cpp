#include "Parallel.h"
#include <iostream>
#include <climits>
#include <vector>
#include <thread>
#include <atomic>

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

    std::atomic<int> nextCol(0);

    auto worker = [&]() {
        while (true) {
            int col = nextCol++;
            if (col >= matrixSize) break;

            int maxElement = INT_MIN;
            for (int i = 0; i < matrixSize; i++) {
                if (matrix[i][col] > maxElement) {
                    maxElement = matrix[i][col];
                }
            }
            maxElements[col] = maxElement;
        }
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < maxThreads; ++i) {
        threads.emplace_back(worker);
    }

    for (auto& t : threads) {
        t.join();
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

void Parallel::updateMatrixDiagonalElements(std::vector<std::vector<int>>& matrix, const std::vector<int>& maxElements, int maxThreads) {
    int matrixSize = matrix.size();
    std::atomic<int> nextRow(0);

    auto worker = [&]() {
        while (true) {
            int row = nextRow++;
            if (row >= matrixSize) break;
            matrix[row][row] = maxElements[row];
        }
    };

    std::vector<std::thread> threads;
    for (int i = 0; i < maxThreads; ++i) {
        threads.emplace_back(worker);
    }

    for (auto& t : threads) {
        t.join();
    }
}
