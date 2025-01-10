#pragma once
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <climits>
#include <memory>
#include <vector>

class Matrix {
private:
    int matrixSize;
    std::vector<std::vector<int>> matrix;
public:
    explicit Matrix(int matrixSize);
    void matrixCreation();
    void printMatrix() const;
    void printDiagonalElements() const;
    std::vector<std::vector<int>>& getMatrix();
};